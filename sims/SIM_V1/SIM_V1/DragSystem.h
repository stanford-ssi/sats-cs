//
// Created by Jason Herrmann on 2019-05-12.
//

#ifndef SIM_V1_DRAGSYSTEM_H
#define SIM_V1_DRAGSYSTEM_H

#include "ForceSystem.h"

namespace EE {
    class DragSystem : public ForceSystem {
    public:

        DragSystem();

        static System* create() { return new DragSystem(); }

        virtual void debug();

    private:

        virtual void update(timeUnit dt);


    };
}


#endif //SIM_V1_DRAGSYSTEM_H
