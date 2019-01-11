#include "System.h"
//#include "entity.h"

class TestSystem;

using namespace EE;

//EE::System::System(const sType& type)
//{
//	type = typeid(*this).name();
//	this->type = type;
//}


void EE::System::addDependency(const cType& name, Component* depend)
{
	if (depend) {
		compDependency[name].insert(depend);
	}
}

void EE::System::removeDependency(const cType& name)
{
	if (dependencies.find(name) != dependencies.end()) {
		compDependency.erase(name);
		dependencies.erase(name);
	}
}

#include <iostream>
#include <string>

void EE::System::debug()
{
	std::cout << "------SYSTEM DEBUG------\n"
		<< "TYPE: " << type << "\n\n"
		<< "%%% DEPENDENCY TYPE TO PTR_SET MAP %%%\n";
	for (auto elem : compDependency) {
		std::cout << elem.first << "  :  {";
		for (auto ptr : elem.second) {
			std::cout << ptr << ", ";
		}
	}

	std::cout << "}\n\n" << "%%% DEPENDENCY SET %%%\n" << "{";
	for (auto elem : dependencies) {
		std::cout << elem << ", ";
	}
	std::cout << "}" << "\n\n";
	
}
