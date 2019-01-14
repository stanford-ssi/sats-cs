/*
  Stanford Student Space Initiative
  Satellites | Sims | December 2018
  Garand Tyson  | gttyson@stanford.edu

  File: TestSystem.cpp
  --------------------------
  Example implimentation of a system.

  WARNING: Must update sRegistry in engine.h when new system added.
*/

#include "TestSystem.h"

// Must include components that will be modified
#include "TestComponent.h"

// Must initialize type to string literal of system name
EE::TestSystem::TestSystem()
{
	type = "TestSystem";
}

// Must impliment update function that changes some component property(s) 
// after a given time interval dt
#include <iostream>
void EE::TestSystem::update(timeUnit dt)
{

	for (auto& comp : compDependency["TestComponent"]) {
		((TestComponent*)comp)->state += dt;
		std::cout << "Current State: " << ((TestComponent*)comp)->state << "\n";
	}
	
}

// Must impliment some debug function
void EE::TestSystem::debug()
{
	// First call should be to parent class debug()
	System::debug();
}

