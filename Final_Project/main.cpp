#include <iostream>
#include "StringSorter.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ifstream inFile("test.txt");
    vector<string> testVector;
    string token;
    while(!inFile.eof()){
        getline(inFile, token);
        if(token != "")
            testVector.push_back(token);
    }

    StringSorter::sortAlphabetically(testVector, true);



    for(int i=0;i<testVector.size();i++){
        cout<<":"<<testVector[i]<<endl;
    }
    return 0;
}
