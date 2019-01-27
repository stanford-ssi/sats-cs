#ifndef DATABASENODE_H
#define DATABASENODE_H
#include <utility>
#include <unordered_map>

class databaseNode{
public:
    databaseNode(int idParameter = NULL);
    int getId(); //returns null
    databaseNode* getChild(int value); //returns a child by reference where value is the number of neighbors or distance
    void addChild(int value, databaseNode* child); //add child with value as the number of neighbors or distance
    databaseNode* removeChild(int value);
    bool isResult(); //returns false
    bool containsChild(int value);

private:
    int numChildren;
    int id;
    std::unordered_map <int, databaseNode*> children; //we could have this be a vector and have the distances be a part of the child, that is what value is for
};

#endif // DATABASENODE_H

/*databaseNode::databaseNode(int idParameter) {
    id = idParameter;
    numChildren = 0;
}

int databaseNode::getId() {
    return id;
}

databaseNode* databaseNode::getChild(int value) {
    return children[value];
}

bool databaseNode::containsChild(int value) {
    if(children.find(value) == children.end()) {
        return false;
    }
    return true;
}

void databaseNode::addChild(int value, databaseNode* child) {
    children.insert({value, child});
}

bool databaseNode::isResult() {
    return id != NULL;
}*/
