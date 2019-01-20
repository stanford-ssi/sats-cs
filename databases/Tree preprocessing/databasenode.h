#ifndef DATABASENODE_H
#define DATABASENODE_H

#include <utility>
#include <unordered_map>
#include <databasesupernode.h>

class databaseNode : public databaseSuperNode{ //decision node
public:
    databaseNode();
    int getId(); //returns null
    databaseSuperNode* getChild(int value); //returns a child by reference where value is the number of neighbors or distance
    void addChild(int value, databaseSuperNode* child); //add child with value as the number of neighbors or distance
    databaseSuperNode* removeChild(int value);
    bool isResult(); //returns false
    bool containsChild(int value);

private:
    int numChildren;
    std::unordered_map <int, databaseSuperNode*> children; //we could have this be a vector and have the distances be a part of the child, that is what value is for
};

databaseNode::databaseNode() {
    //value = initValue;
    numChildren = 0;
}

int databaseNode::getId() {
    return NULL;
}

databaseSuperNode* databaseNode::getChild(int value) {
    return children[value];
}

bool databaseNode::containsChild(int value) {
    if(children.find(value) == children.end()) {
        return false;
    }
    return true;
}

void databaseNode::addChild(int value, databaseSuperNode* child) {
    children.insert({value, child});
}

bool databaseNode::isResult() {
    return false;
}


#endif // DATABASENODE_H
