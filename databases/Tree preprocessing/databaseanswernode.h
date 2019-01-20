#ifndef DATABASEANSWERNODE_H
#define DATABASEANSWERNODE_H

#include <databasesupernode.h>

class databaseAnswerNode : public databaseSuperNode {//answer node
public:
    databaseAnswerNode(int idParameter);
    int getId();
    bool isResult();//returns true
private:
    int id;
};

databaseAnswerNode::databaseAnswerNode(int idParameter) {
    id = idParameter;
}

databaseAnswerNode::int getId() {
    return id;
}
databaseAnswerNode::bool isResult() {
    return true;
}

#endif // DATABASEANSWERNODE_H
