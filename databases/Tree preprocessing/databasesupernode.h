#ifndef DATABASESUPERNODE_H
#define DATABASESUPERNODE_H

class databaseSuperNode { //parent class for decision and answer node
public:
    virtual bool isResult();
    virtual int getId();
    virtual databaseSuperNode* getChild(int value);
    virtual void addChild(int value, databaseSuperNode* child);
    virtual databaseSuperNode* removeChild(int value);
    virtual bool containsChild(int value);
};

#endif // DATABASESUPERNODE_H
