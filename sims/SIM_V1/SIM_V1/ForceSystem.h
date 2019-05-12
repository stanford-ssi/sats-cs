/*
Created by Jason Herrmann on 2019-05-12.

Follows the structure of TestSystem.h and System.h -- a general system class for Forces (all forces will derive from here)

 */

#ifndef SIM_V1_FORCESYSTEM_H
#define SIM_V1_FORCESYSTEM_H

// include requisite classes for subclass
#include "System.h"

// attach to EE namespace
namespace EE {

    // subclass general System
    class ForceSystem : public System {

    public:

        ForceSystem();

        static System* create() { return new ForceSystem(); }

        virtual void debug();

    private:

        virtual void update(timeUnit dt);

    };

}


#endif //SIM_V1_FORCESYSTEM_H
