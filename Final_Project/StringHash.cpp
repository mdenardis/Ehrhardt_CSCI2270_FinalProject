#include <iostream>
#include "StringSorter.h"
#include "StringHash.h"
#include <fstream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

void StringHash::push(string title){
    int i = StringHash::hashSum(title);
    hashElm *hashString; hashString = new hashElm(title);
    if(hashTable[i] == NULL){
        hashTable[i] = hashString;
    }else{
        hashElm *parent; parent = hashTable[i];
        while(parent->next != NULL){
            parent = parent->next;
        }
        parent->next = hashString;
        hashString->next = NULL;
    }
}

StringHash::StringHash(int i){
    hashTable = new hashElm*[i];
}

StringHash::~StringHash(){}

int StringHash::hashSum(string title){
    int sum = 0;
    for(int i=0;i<title.length();i++){
        sum += (int)title[i];
    }
    int s = sum % hashSize;
    s = floor(s);
    return s;
}
