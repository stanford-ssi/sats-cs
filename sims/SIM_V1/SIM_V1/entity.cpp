#include "entity.h"
#include "TestComponent.h"

using namespace EE;



Entity::Entity(const eType& inputName, const eId& idInput)
{
	name = inputName;
	id = idInput;
}

EE::Entity::~Entity()
{
	for (auto& comp : componentSet) {
		delete comp;
	}
}

eType Entity::getName() const
{
	return name;
}

eId Entity::getId() const
{
	return id;
}

const cNameToPtr Entity::getComponentList() const
{
	return componentMap;
}

cNameToPtr Entity::getComponentList()
{
	return componentMap;
}

idCompPtrPair Entity::getComponentPair(const cType& comp) {
	
	// TODO: Impliment
	return std::make_pair(id, nullptr);
}

bool Entity::contains(const cType& comp) const
{
	return componentMap.find(comp) != componentMap.end();
}

Component const * const Entity::getComponent(const cType& type) const
{
	if (type.empty()) {
		throw "Invalid component name.";
	}
	if (componentMap.find(type) == componentMap.end()) {
		throw "Component not found";
	}
	return componentMap.at(type);
}

Component* Entity::getComponent(const cType& type)
{
	if (type.empty()) {
		return nullptr;
	}
	if (componentMap.find(type) == componentMap.end()) {
		return nullptr;
	}
	return componentMap.at(type);
}

// TODO: FIX IF STATEMENT
void Entity::addComponent(Component* comp) 
{

	componentMap[comp->getType()] = comp;
	componentSet.insert(comp);

}

void Entity::removeComponent(const cType& comp)
{
	if (componentMap.find(comp) == componentMap.end()) {
		throw "ERROR: ENTITY DOES NOT CONTAIN COMPONENT";
	}
	componentSet.erase(componentMap[comp]);
	componentMap.erase(comp);

}

cPtrSet Entity::getComponentSet() const
{
	return componentSet;
}

#include <iostream>
#include <string>

void Entity::debug()
{
	std::cout << "------ENTITY DEBUG------\n"
		<< "ID: " << id << "\n"
		<< "Name:  " << name << "\n\n"
		<< "%%% COMPONENT SET %%%\n";
	for (auto comp : componentSet) {
		std::cout << comp << ", ";
	}
	std::cout << "\n\n"
		<< "%%% COMPONENT MAP %%%\n";
	for (auto comp : componentMap) {
		std::cout << comp.first << "  :  " << comp.second << "\n";
	}
	std::cout << "\n" 
		<< "------CCOMPONENT DEBUG------\n";
	for (auto comp : componentMap) {
		std::cout << "Parent Entity ID: " << id << "\n";
		comp.second->debug();
	}
	std::cout << "\n";
}

