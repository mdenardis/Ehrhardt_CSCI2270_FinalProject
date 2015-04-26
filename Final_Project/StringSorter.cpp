#include <iostream>
#include "StringSorter.h"
#include <vector>
#include <string>

using namespace std;

bool StringSorter::isABigger(string a, string b){
    int shortString;
    if(a.length() > b.length()){
        shortString = b.length();
    }else{
        shortString  = a.length();
    }
    for(int i=0;i<shortString;i++){
        if(a[i] > b[i]){
            return true;
        }else if (b[i] > a[i]){
            return false;
        }
    }
    cout<<"same word or error"<<endl;
    return false;
}

void StringSorter::sortAlphabetically(vector<string> &stringVector, bool isAscending){
    if(isAscending){
        string index; int j;
        for(int i=0;i<stringVector.size();i++){
            index = stringVector[i];
            j = i;
            while((j>0) && (StringSorter::isABigger(stringVector[j - 1], index))){
                stringVector[j] = stringVector[j - 1];
                j -= 1;
            }
            stringVector[j] = index;
        }
    }else{
        string index; int j;
        for(int i=0;i<stringVector.size();i++){
            index = stringVector[i];
            j = i;
            while((j>0) && (!StringSorter::isABigger(stringVector[j - 1], index))){
                stringVector[j] = stringVector[j - 1];
                j -= 1;
            }
            stringVector[j] = index;
        }
    }
}

