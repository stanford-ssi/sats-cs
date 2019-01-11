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