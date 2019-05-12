//
// Created by Jason Herrmann on 2019-05-12.
//

#include "DragSystem.h"
#include "TestComponent.h"

// Must initialize type to string literal of system name -- this is the constructor method
EE::DragSystem::DragSystem()
{
    ForceSystem();
    type = "DragSystem";
}

// Must impliment update function that changes some component property(s)
// after a given time interval dt
#include <iostream>
void EE::DragSystem::update(timeUnit dt)
{

    // loop over all components of particular type in the dependencies -- how exactly does this chunk work?
    for (auto& comp : compDependency["TestComponent"]) {
        ((TestComponent*)comp)->state += dt;
        std::cout << "Current State: " << ((TestComponent*)comp)->state << "\n";

        // TODO - PERFORM UPDATES ON COMPONENTS
    }

}

// Must impliment some debug function
void EE::DragSystem::debug()
{
    // First call should be to parent class debug()
    ForceSystem::debug();

    std::cout << "Drag At Break: " << type;
}

