#include <iostream>
#include "StringSorter.h"
#include <vector>
#include <string>

using namespace std;

/*
Function prototype: bool isABigger(string, string);
Function description: returns boolean value depending on the char value of two strings.
will return boolean depending if the values of the first string is larger than the other string.
Example:
if(StringSorter::isABigger("hello", "goodbye"){
    ...
}
Precondition:Any two strings.
Postcondition:Boolean that tells which is bigger.
*/

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

/*
Function prototype: sortAlphabetically(vector<string> &, bool);
Function description:sorts vector alphabetically, depending on the boolean it will doing it
in ascending or descending order.
Example:
vector<string> example;
StringSorter::sortAlphabetically(example, true);
Precondition:a vector of strings and a boolean value.
Postcondition:the original vector alphabeticaly sorted
*/

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

