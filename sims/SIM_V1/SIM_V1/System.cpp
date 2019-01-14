/*
  Stanford Student Space Initiative
  Satellites | Sims | December 2018
  Garand Tyson  | gttyson@stanford.edu

  File: System.cpp
  --------------------------
  Abstract parent class for system implimentation.

  WARNING: Must update sRegistry in engine.h when new system added.
*/

#include "System.h"

class TestSystem;

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
