#ifndef GENERATETREE_H
#define GENERATETREE_H

#include <databasenode.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void generateTree(ifstream& file) {
    databaseNode* root = new databaseNode();
    int currID = 0;
    int numNeighbors = 0;
    string currLine = "";
    //location
    while(getline(file, currLine)) { //loops over each line in csv file
        istringstream sStream (currLine);
        sStream >> currID;
        sStream >> numNeighbors;
        int currValue = numNeighbors;
        databaseNode* currLevel = root;

        for(int currNeighbor = 0; currNeighbor <= numNeighbors; currNeighbor++) { //loops over all details for current star
            if(!currLevel->containsChild(currValue)) { //if the current level doesnt have that node add it
                if(currNeighbor < numNeighbors) { //add a decision node
                    databaseNode* decisionNode = new databaseNode();
                    currLevel->addChild(currValue, decisionNode);
                }
                else {//add an answer node
                    databaseNode* answerNode = new databaseNode(currID);
                    currLevel->addChild(currValue, answerNode);
                }
            }
            currLevel = currLevel->getChild(currValue); //go to next level in database
            sStream >> currValue; //go to next value to enter in to database
        }
    }
}

#endif // GENERATETREE_H
