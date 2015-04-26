#include <iostream>
#include "StringSorter.h"
#include "StringHash.h"
#include <fstream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

void StringHash::print(bool isAcending){
    vector<string> abcSort;
    for(int i=0;i<hashSize;i++){
        hashElm *temp; temp = hashTable[i];
        if(temp != NULL){
            abcSort.push_back(temp->title);
            while(temp->next != NULL){
                temp = temp->next;
                abcSort.push_back(temp->title);
            }
        }
    }
    if(isAcending){
        StringSorter::sortAlphabetically(abcSort, true);
    }else{
        StringSorter::sortAlphabetically(abcSort, false);
    }
    for(int j=0;j<abcSort.size();j++){
        cout<<abcSort[j]<<endl;
    }
}

void StringHash::print(){
    for(int i=0;i<hashSize;i++){
        hashElm *temp; temp = hashTable[i];
        if(temp != NULL){
            cout<<temp->title<<endl;
            while(temp->next != NULL){
                temp = temp->next;
                cout<<temp->title<<endl;
            }
        }
    }
}
void StringHash::pop(string title){
    int i = StringHash::hashSum(title);
    if(hashTable[i]->title == title){
        hashElm *temp; temp = hashTable[i];
        hashTable[i] = temp->next;
        delete temp;
    }else{
        hashElm *parent; hashElm *child;
        parent = hashTable[i];
        if(parent->next != NULL){
            child = parent->next;
            while(child != NULL){
                if(child->title == title){
                    parent->next = child->next;
                    delete child;
                    return;
                }
                child = child->next;
                parent = parent->next;
            }
            if(child == NULL){
                cout<<"String not found"<<endl;
                return;
            }
        }
    }
}

void StringHash::push(string title){
    int i = StringHash::hashSum(title);
    hashElm *hashString; hashString = new hashElm(title);
    if(hashTable[i] == NULL){
        hashTable[i] = hashString;
    }else{
        hashElm *parent; parent = hashTable[i];
        if(parent->next != NULL){
            do{
                parent = parent->next;
            }while(parent->next != NULL);
        }
        parent->next = hashString;
        hashString->next = NULL;
    }
}

StringHash::StringHash(int i){
    hashTable = new hashElm*[i];
    hashSize = i;
}

StringHash::~StringHash(){
    delete hashTable;
}

int StringHash::hashSum(string title){
    int sum = 0;
    for(int i=0;i<title.length();i++){
        sum += (int)title[i];
    }
    int s = sum % hashSize;
    s = floor(s);
    return s;
}
