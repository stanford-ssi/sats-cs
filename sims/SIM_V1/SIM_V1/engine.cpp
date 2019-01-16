/*
  Stanford Student Space Initiative
  Satellites | Sims | December 2018
  Garand Tyson  | gttyson@stanford.edu

  File: engine.cpp
  --------------------------
  Impliments engine.h

  WARNING: Must update sRegistry when new system added.
  WARNING: Must update cRegistry when new component added.
*/

#include "Engine.h"

/*
 * Function: loadSpace
 * -------------------
 * This function sets a space as the active space for the engine.
 */
void EE::Engine::loadSpace(Space* space) {
	currentSpace = space;
}

/*
 * Function: loadSpace
 * -------------------
 * This function sets a space as the active space for the engine.
 */
void EE::Engine::addEntity(const eType& name) 
{
	if (name.empty()) {
		throw "Invalid name.";
	}
	if (currentSpace->idToName.find(currentSpace->nextId) != currentSpace->idToName.end()) {
		throw "Name already used.";
	}
	currentSpace->idToPointer[currentSpace->nextId] = new Entity(name, currentSpace->nextId);
	currentSpace->idToName[currentSpace->nextId] = name;
	currentSpace->nameToId[name] = currentSpace->nextId;
	++currentSpace->nextId;
}

// Removes and deletes an entity
void EE::Engine::removeEntity(const eType& name)
{
	if (name.empty()) {
		throw "Invalid name.";
	}
	if (currentSpace->nameToId.find(name) == currentSpace->nameToId.end()) {
		throw "Entity \"" + name + "\" not found.";
	}
	const eId& id = currentSpace->nameToId[name];
	currentSpace->idToName.erase(id);
	Entity* &ptr = currentSpace->idToPointer[id];
	// Update Systems
	for (auto& comp : ptr->getComponentList()) {
		for (auto& sys : currentSpace->sNameToPointer) {
			if (sys.second->dependencies.find(comp.first) != sys.second->dependencies.end()) {
				sys.second->compDependency[comp.first].erase(comp.second);
			}
		}
	}
	delete ptr;
	ptr = 0;
	currentSpace->idToPointer.erase(id);
	currentSpace->nameToId.erase(name);
}

// Ref: https://stackoverflow.com/questions/14508076/create-an-object-according-to-a-string-in-c
void EE::Engine::addSystem(const sType& system)
{
	/*if (currentSpace->sNameToPointer.find(system) != currentSpace->sNameToPointer.end()) {
		throw "ERROR: SYSTEM ALREADY EXISTS";
	}
	if (system == "TestSystem") {
		// Create System and update collections
		currentSpace->sysUpdateOrder.push_back(system);
		System* ptr = new TestSystem();
		currentSpace->sNameToPointer[system] = ptr;
	}
	else {
		throw "ERROR: INVALID SYSTEM NAME";
	}*/
	auto it = sRegistry.find(system);
	if (it == sRegistry.end()) {
		throw "INVALID SYSTEM NAME";
	} else {
		// Create System and update collections
		currentSpace->sysUpdateOrder.push_back(system);
		currentSpace->sNameToPointer[system] = (it->second)();
	}
}

void EE::Engine::removeSystem(const sType& system)
{
	if (currentSpace->sNameToPointer.find(system) == currentSpace->sNameToPointer.end()) {
		throw "ERROR: SYSTEM NOT FOUND";
	}
	// Delete system from heap
	delete currentSpace->sNameToPointer[system];
	// Delete system pointer in space map
	currentSpace->sNameToPointer.erase(system);
	// Remove System from update order
	currentSpace->sysUpdateOrder.erase(std::remove(currentSpace->sysUpdateOrder.begin(),
		currentSpace->sysUpdateOrder.end(), system), currentSpace->sysUpdateOrder.end());
}

EE::Entity* EE::Engine::getEntity(const eType& name) 
{
	return currentSpace->idToPointer[currentSpace->nameToId[name]];
}

EE::System* EE::Engine::getSystem(const sType& name)
{
	return currentSpace->sNameToPointer[name];
}

void EE::Engine::addComponent(const eType& eName, const cType& comp) 
{	
	auto it = cRegistry.find(comp);
	if (it == cRegistry.end()) {
		throw "INVALID COMPONENT NAME";
	}
	auto& ePtr = currentSpace->idToPointer[currentSpace->nameToId[eName]];
	Component* cPtr = (it->second)();
	ePtr->addComponent((it->second)());
	// Update System
	for (auto sys : currentSpace->sNameToPointer) {
		if (sys.second->dependencies.find(comp) != sys.second->dependencies.end()) {
			sys.second->addDependency(comp, cPtr);
		}
	}
	
	
}

void EE::Engine::removeComponent(const eType& eName, const cType& comp)
{
	auto& ePtr = currentSpace->idToPointer[currentSpace->nameToId[eName]];
	ePtr->removeComponent(comp);
	// Update System
	for (auto& sys : currentSpace->sNameToPointer) {
		sys.second->removeDependency(comp);
	}
}

void EE::Engine::addSysDependency(const sType& sys, const cType& depend) {
	auto& ptr = currentSpace->sNameToPointer[sys];
	ptr->dependencies.insert(depend);
	for (auto& ent : currentSpace->idToPointer) {
		auto cPtr = ent.second->getComponent(depend);
		if (cPtr) {
			ptr->addDependency(depend, cPtr);
		}
	}
}

void EE::Engine::removeSysDependency(const sType& sys, const cType& depend)
{
	currentSpace->sNameToPointer[sys]->removeDependency(depend);
}

void EE::Engine::update()
{
	for (auto iter = currentSpace->sysUpdateOrder.begin();
		iter != currentSpace->sysUpdateOrder.end(); ++iter) {

		currentSpace->sNameToPointer[*iter]->update(currentSpace->dt);
	}
}

void EE::Engine::debugEntity(const eType& name) 
{
	currentSpace->idToPointer[currentSpace->nameToId[name]]->debug();
}

#include <iostream>
#include <string>

void EE::Engine::debugSpace()
{
	std::cout << "------SPACE DEBUG------\n"
		<< "NEXT ID: " << currentSpace->nextId << "\n"
		<< "CURRENT SPACE:  " << currentSpace << "\n\n"
		<< "%%% ID TO NAME MAP %%%\n";
	for (auto elem : currentSpace->idToName) {
		std::cout << elem.first << "  :  " << elem.second << "\n";
	}

	std::cout << "\n" << "%%% NAME TO ID MAP %%%\n";
	for (auto elem : currentSpace->nameToId) {
		std::cout << elem.first << "  :  " << elem.second << "\n";
	}

	std::cout << "\n" << "%%% ID TO PTR MAP %%%\n";
	for (auto elem : currentSpace->idToPointer) {
		std::cout << elem.first << "  :  " << elem.second << "\n";
	}
	
	std::cout << "\n" << "%%% SYSTEM UPDATE ORDER %%%\n";
	for (auto iter = currentSpace->sysUpdateOrder.begin();
		iter != currentSpace->sysUpdateOrder.end(); ++iter) {

		std::cout << *iter << ", ";
	}

	std::cout << "\n\n" << "%%% SYSTEM NAME TO PTR MAP %%%\n";
	for (auto elem : currentSpace->sNameToPointer) {
		std::cout << elem.first << "  :  " << elem.second << "\n";
	}
	std::cout << "\n";
}

void EE::Engine::debugSystem(const cType& system)
{
	currentSpace->sNameToPointer[system]->debug();
}

/*******************************  SINGLETON SUPPORT ********************************/

EE::Engine* EE::Engine::m_pInstance = NULL;

EE::Engine* EE::Engine::Instance()
{
	/* Ensures only 1 instance exists */
	if (!m_pInstance) {
		m_pInstance = new Engine;
	}
	return m_pInstance;
}