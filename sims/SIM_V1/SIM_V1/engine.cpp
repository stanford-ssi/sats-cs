#include "Engine.h"
#include <iostream>
#include <algorithm>
#include <stddef.h>

using namespace EE;

Engine* Engine::m_pInstance = NULL;

Engine* Engine::Instance()
{
	if (!m_pInstance) {
		// Ensures only 1 instance exists
		m_pInstance = new Engine;
	}

	return m_pInstance;
}

Engine::Engine()
{
	nextId = 0;
	time = 0.0;
}

void Engine::loadSpace(Space* space) {
	currentSpace = space;
}

void Engine::addEntity(const eType& name) 
{
	if (name.empty()) {
		throw "Invalid name.";
	}
	if (currentSpace->idToName.find(nextId) != currentSpace->idToName.end()) {
		throw "Name already used.";
	}
	currentSpace->idToPointer[nextId] = new Entity(name, nextId);
	currentSpace->idToName[nextId] = name;
	currentSpace->nameToId[name] = nextId;
	//systemAddDependencyEvent.connect(&Entity::getComponentPair);
	++nextId;
}

// Removes and deletes an entity
void Engine::removeEntity(const eType& name)
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

Entity* Engine::getEntity(const eType& name) 
{
	return currentSpace->idToPointer[currentSpace->nameToId[name]];
}

System* Engine::getSystem(const sType& name)
{
	return currentSpace->sNameToPointer[name];
}

void Engine::addComponent(const eType& eName, const cType& comp) 
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

void Engine::removeComponent(const eType& eName, const cType& comp)
{
	auto& ePtr = currentSpace->idToPointer[currentSpace->nameToId[eName]];
	ePtr->removeComponent(comp);
	// Update System
	for (auto& sys : currentSpace->sNameToPointer) {
		sys.second->removeDependency(comp);
	}
}

void Engine::addSysDependency(const sType& sys, const cType& depend) {
	auto& ptr = currentSpace->sNameToPointer[sys];
	ptr->dependencies.insert(depend);
	for (auto& ent : currentSpace->idToPointer) {
		auto cPtr = ent.second->getComponent(depend);
		if (cPtr) {
			ptr->addDependency(depend, cPtr);
		}
	}
}

void Engine::removeSysDependency(const sType& sys, const cType& depend)
{
	currentSpace->sNameToPointer[sys]->removeDependency(depend);
}

void Engine::update(timeUnit dt)
{
	for (auto iter = currentSpace->sysUpdateOrder.begin();
		iter != currentSpace->sysUpdateOrder.end(); ++iter) {

		currentSpace->sNameToPointer[*iter]->update(dt);
	}
}

void Engine::debugEntity(const eType& name) 
{
	currentSpace->idToPointer[currentSpace->nameToId[name]]->debug();
}

#include <iostream>
#include <string>

void Engine::debugSpace()
{
	std::cout << "------SPACE DEBUG------\n"
		<< "NEXT ID: " << nextId << "\n"
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

void Engine::debugSystem(const cType& system)
{
	currentSpace->sNameToPointer[system]->debug();
}