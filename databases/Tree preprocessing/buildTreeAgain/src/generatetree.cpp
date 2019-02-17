#ifndef GENERATETREE_H
#define GENERATETREE_H

#include "databasenode.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unistd.h>

using namespace std;

// Each row of dataPoints is in the form: ID, N, D1, D2, D3, D4, D5
// returns root
databaseNode* generateTree(vector<vector<int>> allDataPoints) {
    databaseNode* root = new databaseNode();
    //location
    for (int i = 0; i < 1; i++) { //loops over each data point
        vector<int> dataPoint = allDataPoints[i];
        int currID = dataPoint[0];
        int numNeighbors = dataPoint[1];
        cout << "currID: " << currID << endl;

        databaseNode* currNode = root;

        for(int j = 0; j < numNeighbors; j++) { // loops over D1, D2, D3, D4, D5 for current star, skip ID and N

            int currValue = dataPoint[2 + j]; // offset by 2 for ID and N
            if(!currNode->containsChild(currValue)) { //if the current level doesnt have that node add it
                if(j < numNeighbors - 1) { //add a decision node
                    databaseNode* decisionNode = new databaseNode();
                    currNode->addChild(currValue, decisionNode);
                    cout << "decision node added with currValue: " << currValue << endl;
                }
                else { // last iteration, add final decision node, then the answer node
                    databaseNode* decisionNode = new databaseNode();
                    currNode->addChild(currValue, decisionNode);
                    cout << "decision node added with currValue: " << currValue << endl;

                    currNode = currNode->getChild(currValue); // go to next level in database

                    databaseNode* answerNode = new databaseNode(currID);
                    currNode->addChild(currID, answerNode);
                    cout << "answer node added ID: " << currID << endl;
                    break; // done inserting this dataPoint into the tree
                }
            }

            currNode = currNode->getChild(currValue); //go to next level in database
        }
    }
    return root;
}


#endif // GENERATETREE_H
