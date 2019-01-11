#include "TestComponent.h"

#include <iostream>
#include <string>

EE::TestComponent::TestComponent()
{
	type = "TestComponent";
}

void EE::TestComponent::debug()
{
	Component::debug();
	std::cout << "STATE:  " << state << "\n\n";
}