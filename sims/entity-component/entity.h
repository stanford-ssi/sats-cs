#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <unordered_map>
#include <typeinfo>
#include "component.h"


class Entity
{
public:
    Entity(std::string, unsigned int);
    std::string getName();
    unsigned int getId();

    std::unordered_map <std::string, Component> getComponents();

    bool contains(Component);
    bool contains(std::string);

    Component& getComponent(Component);
    Component& getComponent(std::string);

    void addComponent(Component);

private:
    unsigned int id;
    std::string name;

    std::unordered_map <std::string, Component> listOfComponents;

};

#endif // ENTITY_H
