#include "TestSystem.h"
#include <iostream>
#include "TestComponent.h"

EE::TestSystem::TestSystem()
{
	type = "TestSystem";
}

void EE::TestSystem::update(timeUnit dt)
{

	for (auto& comp : compDependency["TestComponent"]) {
		((TestComponent*)comp)->state += dt;
		std::cout << "Current State: " << ((TestComponent*)comp)->state << "\n";
	}
	
}

void EE::TestSystem::debug()
{
	System::debug();
}

