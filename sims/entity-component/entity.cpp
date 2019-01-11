#include "entity.h"
#include "component.h"
#include <unordered_map>

using namespace std;

//listOfComponents is an unordered map that has a string as its key and a Component as its value, the string is the class name

Entity::Entity(std::string inputName, unsigned int idInput) {
    name = inputName;
    id = idInput;
}
std::string Entity::getName() {
    return name;
}
unsigned int Entity::getId() {
    return id;
}

std::unordered_map <std::string, Component> Entity::getComponents() {
    return listOfComponents;
}

Component& Entity::getComponent(Component comp) { //returned by reference so changes are reflected in entity
    string type = typeid(comp).name(); //this returns the class name of comp
    return getComponent(type);
}

Component& Entity::getComponent(std::string type) { //the redundant methods allow the user to use either component name or actual component
    if(contains(type)) {
        return listOfComponents.at(type); //returns component if found
    }
    else {
        throw -1; // else throws exception
    }
}

void Entity::addComponent(Component comp) {
    string type = typeid(comp).name();
    listOfComponents.insert( {type, comp} );
}

bool Entity::contains(Component comp) {
    string type = typeid(comp).name();
    return contains(type);
}

bool Entity::contains(std::string type) {
    if(listOfComponents.find(type) != listOfComponents.end()) {
        return true;
    }
    else {
        return false;
    }
}


