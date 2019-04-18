//
// Created by Jason Herrmann on 2019-04-17.
//

#ifndef SSI_SIMULATION_DRAG_H
#define SSI_SIMULATION_DRAG_H

#include "Force.h"
#include <string>
using namespace std;

class Drag : public Force {
private:
    string model;
public:
    Drag(int simEntity, int dragEntityArray);
    int UpdateDrag(int position, int velocity);
};

Drag::Drag(int simEntity, int dragEntityArray) {
    model = "hello, world!";
}

int Drag::UpdateDrag(int position, int velocity) {

    return 0;
}


#endif //SSI_SIMULATION_DRAG_H
