/*
  Stanford Student Space Initiative
  Satellites | Sims | December 2018
  Garand Tyson  | gttyson@stanford.edu

  File: component.cpp
  --------------------------
  Abstract parent class for component implimentation.

  WARNING: Must update cRegistry in engine.h when new component added.
*/

#include "component.h"

EE::cType EE::Component::getType() const
{
	return type;
}

#include <iostream>
#include <string>
void EE::Component::debug()
{
	std::cout << "Name:  " << type << "\n\n";
}