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
 * Function: addEntity
 * -------------------
 * This function adds an entity with name eType name and with the current
 * space's next available id number.
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

/*
 * Function: removeEntity
 * -------------------
 * This function removes an entity with name eType from the current space.
 */
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
	/* Updates System Dependency lists */
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

/*
 * Function: addSystem
 * -------------------
 * This function adds a System of sType system to the current space. Assumes System is not already
 * added. Throws error if system not in sRegistry in engine.h.
 * TODO: Add protection for adding system already in space
 * Ref: https://stackoverflow.com/questions/14508076/create-an-object-according-to-a-string-in-c
 */
void EE::Engine::addSystem(const sType& system)
{
	/* Find System in registry */
	auto it = sRegistry.find(system);
	if (it == sRegistry.end()) {
		throw "INVALID SYSTEM NAME";
	} else {
		/* Create System and update collections */
		currentSpace->sysUpdateOrder.push_back(system);
		currentSpace->sNameToPointer[system] = (it->second)();
	}
}

/*
 * Function: removeSystem
 * -------------------
 * This function removes a Ssytem of sType system from the current space. If system does
 * not exist on current space, function throws error.
 */
void EE::Engine::removeSystem(const sType& system)
{
	if (currentSpace->sNameToPointer.find(system) == currentSpace->sNameToPointer.end()) {
		throw "ERROR: SYSTEM NOT FOUND";
	}
	/* Delete system from heap */
	delete currentSpace->sNameToPointer[system];
	/* Delete system pointer in space map */
	currentSpace->sNameToPointer.erase(system);
	/* Remove System from update order */
	currentSpace->sysUpdateOrder.erase(std::remove(currentSpace->sysUpdateOrder.begin(),
		currentSpace->sysUpdateOrder.end(), system), currentSpace->sysUpdateOrder.end());
}

/*
 * Function: getEntity
 * -------------------
 * Returns Entity* of type eType name from the current space. Returns nullptr if
 * entity does not exist on current space.
 */
EE::Entity* EE::Engine::getEntity(const eType& name) 
{
	return currentSpace->idToPointer[currentSpace->nameToId[name]];
}

/*
 * Function: getSystem
 * -------------------
 * Returns System* of type sType name from the current space. Returns nullptr if
 * system does not exist on current space.
 */
EE::System* EE::Engine::getSystem(const sType& name)
{
	return currentSpace->sNameToPointer[name];
}

/*
 * Function: addComponent
 * -------------------
 * Adds component of cType comp to entity of eType name to current space. If component
 * is not on cRegistry in engine.h, throws error.
 * Assumes entity exists on current space, seg faults if not.
 * TODO: Add protection for invalid entity entry
 */
void EE::Engine::addComponent(const eType& eName, const cType& comp) 
{	
	auto it = cRegistry.find(comp);
	if (it == cRegistry.end()) {
		throw "INVALID COMPONENT NAME";
	}
	auto& ePtr = currentSpace->idToPointer[currentSpace->nameToId[eName]];
	Component* cPtr = (it->second)();
	ePtr->addComponent((it->second)());
	/* Update System */
	for (auto sys : currentSpace->sNameToPointer) {
		if (sys.second->dependencies.find(comp) != sys.second->dependencies.end()) {
			sys.second->addDependency(comp, cPtr);
		}
	}
}

/*
 * Function: removeComponent
 * -------------------
 * Removes component of cType comp from entity of eType name from current space. If component
 * is not on cRegistry in engine.h, throws error.
 * Assumes entity exists on current space, seg faults if not.
 * TODO: Add protection for invalid entity entry
 */
void EE::Engine::removeComponent(const eType& eName, const cType& comp)
{
	auto& ePtr = currentSpace->idToPointer[currentSpace->nameToId[eName]];
	ePtr->removeComponent(comp);
	/* Update System */
	for (auto& sys : currentSpace->sNameToPointer) {
		sys.second->removeDependency(comp);
	}
}

/*
 * Function: addSysDependency
 * -------------------
 * Add component dependency of cType depend to System of sType sys.
 * Assumes system and component exist.
 * TODO: Add protection for invalid systems and components.
 */
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

/*
 * Function: removeSysDependency
 * -------------------
 * Removes component dependency of cType depend from System of sType sys.
 * Assumes system and component exist.
 * TODO: Add protection for invalid systems and components.
 */
void EE::Engine::removeSysDependency(const sType& sys, const cType& depend)
{
	currentSpace->sNameToPointer[sys]->removeDependency(depend);
}

/*
 * Function: update
 * -------------------
 * Calls update function on each system in the current space in the order specified by 
 * sysUpdateOrder with the timestamp parameter dt from the current space.
 */
void EE::Engine::update()
{
	for (auto iter = currentSpace->sysUpdateOrder.begin();
		iter != currentSpace->sysUpdateOrder.end(); ++iter) {

		currentSpace->sNameToPointer[*iter]->update(currentSpace->dt);
	}
}

/*
 * Function: debugEntity
 * -------------------
 * Calls the debug function for entity of eType name.
 * Assumes entity exists.
 * TODO: Add protection for invalid entities.
 */
void EE::Engine::debugEntity(const eType& name) 
{
	currentSpace->idToPointer[currentSpace->nameToId[name]]->debug();
}

/*
 * Function: debugSystem
 * -------------------
 * Calls the debug function for System of sType system.
 * Assumes system exists.
 * TODO: Add protection for invalid systems.
 */
void EE::Engine::debugSystem(const sType& system)
{
	currentSpace->sNameToPointer[system]->debug();
}

/*
 * Function: debugSpace
 * -------------------
 * Prints several debug statements about current space.
 */
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