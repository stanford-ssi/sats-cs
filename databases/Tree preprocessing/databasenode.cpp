#include <databasenode.h>

databaseNode::databaseNode(int idParameter) {
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
}
