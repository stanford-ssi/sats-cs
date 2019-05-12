//
// Created by Jason Herrmann on 2019-05-12.
//

#include "ForceSystem.h"
#include "TestComponent.h"

// Must initialize type to string literal of system name -- this is the constructor method
EE::ForceSystem::ForceSystem()
{
    type = "ForceSystem";
}

// Must impliment update function that changes some component property(s)
// after a given time interval dt
#include <iostream>
void EE::ForceSystem::update(timeUnit dt)
{

    for (auto& comp : compDependency["TestComponent"]) {
        ((TestComponent*)comp)->state += dt;
        std::cout << "Current State: " << ((TestComponent*)comp)->state << "\n";
    }

}

// Must impliment some debug function
void EE::ForceSystem::debug()
{
    // First call should be to parent class debug()
    System::debug();

    std::cout << "Force At Break: " << type;
}

