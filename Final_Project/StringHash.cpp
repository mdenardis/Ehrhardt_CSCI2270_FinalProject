#include <iostream>
#include "StringSorter.h"
#include "StringHash.h"
#include <fstream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

/*
Function prototype: int getStringData(std:string);
Function description:returns data associated with string.
Example:
StringHash example(10);
... fill with data
string title;
int i = example.getStringData(title)
Precondition: hashTable that is not empty
Postcondition: an integer associated with string input
*/

int StringHash::getStringData(std::string title){
    int i = StringHash::hashSum(title);
    if(hashTable[i] == NULL){
        cout<<"String not found"<<endl;
        return 0;
    }else{
        hashElm *temp; temp = hashTable[i];
        while(temp != NULL){
            if(temp->title == title){
                return temp->data;
            }
            temp = temp->next;
        }
        if(temp == NULL){
            cout<<"String not found"<<endl;
            return 0;
        }
    }
}

/*
Function prototype: void print(bool);
Function description:prints all elements in table in Ascending or Descending order.
Example:
StringHash example(10);
... fill with data
example.print(true);
Precondition:a StringHash that is not empty.
Postcondition: List of what's in StringHash posted in terminal.
*/

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

/*
Function prototype:void print(bool);
Function description:prints StringHash object's contents in current state.
Example:
StringHash example(10);
... fill with data
example.print();
Precondition:A StringHash object that is not empty.
Postcondition: List of what's in StringHash posted on the terminal.
*/

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
/*
Function prototype: void pop(string);
Function description: removes string from table if the title is included
Example:
StringHash example(10);
... fill with data
string value = //string inside hash table...
example.pop(value);
Precondition:A StringHash object that is not empty and a string of the desired node to delete
Postcondition:A StringHash object that does not have the undesired node.
*/
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

/*
Function prototype: void push(string, int);
Function description: adds string and data to StringHash object.
Example:
StringHash example(10);
example.push("title", 10);
Precondition: A StringHash object, a string, and an integer.
Postcondition: A StringHash object with a new node with the string and integer data applied.
*/

void StringHash::push(string title, int data){
    int i = StringHash::hashSum(title);
    hashElm *hashString; hashString = new hashElm(title, data);
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
//constructor
StringHash::StringHash(int i){
    hashTable = new hashElm*[i];
    hashSize = i;
}
//constructor
StringHash::StringHash(){}
///destructor
StringHash::~StringHash(){
    delete hashTable;
}
/*
Function prototype: int hashSum(string);
Function description: returns hash sum based off of string supplied. Used to index hashTable.
Example:
string value;
int i = hashSum(value);
Precondition:a string value.
Postcondition: an integer with hash sum of string supplied.
*/
int StringHash::hashSum(string title){
    int sum = 0;
    for(int i=0;i<title.length();i++){
        sum += (int)title[i];
    }
    int s = sum % hashSize;
    s = floor(s);
    return s;
}
