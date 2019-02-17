#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unistd.h>

#include "databasenode.h"
#include "generatetree.h"

using namespace std;


void promptUserForFile(ifstream& input, string prompt, string reprompt);
void readDataPointsFromFile(ifstream& input, vector<vector<int>>& dataPoints);
void printTree(databaseNode* root);

int main()
{
    ifstream input;
    input.open("/Users/Priscilla/Qt5.10.0/buildTreeAgain/res/sample1.csv");
    if(!input.is_open()) cout << "not open" << endl;
    //promptUserForFile(input, "Please enter file name: ", "Could not open file. Please try again: ");
    vector<vector<int>> allDataPoints;
    readDataPointsFromFile(input, allDataPoints);

    // testing: print out the contents in the vector
    for (unsigned int i = 0; i < allDataPoints.size(); i++) {
        for (unsigned int j = 0; j < allDataPoints[i].size(); j++) {
            cout << allDataPoints[i][j];
            if (j < allDataPoints[i].size() - 1) cout << ", ";
        }
        cout << '\n';
    }


    generateTree(allDataPoints);
    return 0;
}


/*
 * Prompts user for file and opens it.
*/
void promptUserForFile(ifstream& input, string prompt, string reprompt) {
    string fileName;
    cout << prompt;
    while(true) {
        getline(cin, fileName);
        string fileNameFull = "buildTreeAgain/res/" + fileName;
        cout << fileNameFull << endl;
        input.open(fileNameFull);
        if(!input.is_open()) cout << reprompt;
        else break;
    }

}

/*
 * Places data in file into vector of vectors. Inner vectors are the rows.
*/
void readDataPointsFromFile(ifstream& input, vector<vector<int>>& dataPoints) {

    string line;
    int i = 0;
    while (getline(input, line)) {
        if (i == 0) {
            i++;
            continue; // skip the first line, just a header
         }
        vector<int> row;
        dataPoints.push_back(row);

        // Break down the row into column values
        stringstream split(line);
        string token;

        while (getline(split, token, ',')) {
            dataPoints.back().push_back(stoi(token));
        }

    }

}

