#ifndef DATABASENODE_H
#define DATABASENODE_H
#include <utility>
#include <unordered_map>

class databaseNode{
public:
    databaseNode(int idParameter = 0);
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
