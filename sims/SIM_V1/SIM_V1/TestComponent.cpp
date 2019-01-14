/*
  Stanford Student Space Initiative
  Satellites | Sims | December 2018
  Garand Tyson  | gttyson@stanford.edu

  File: TestComponent.cpp
  --------------------------
  Example implimentation of a component.

  WARNING: Must update cRegistry in engine.h when new component added.
*/

#include "TestComponent.h"

// Must initialize type to string literal of component name
EE::TestComponent::TestComponent()
{
	type = "TestComponent";
}

// Some sort of debug has to be implimented, here is a simple example:
#include <iostream>
#include <string>
void EE::TestComponent::debug()
{
	// First call should be to parent class debug()
	Component::debug();
	std::cout << "STATE:  " << state << "\n\n";
}