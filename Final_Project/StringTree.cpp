#include <iostream>
#include "StringSorter.h"
#include "StringTree.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;

StringTree::~StringTree(){}

StringTree::StringTree(){
    nil = new treeElm();
    nil->right = nil; nil->left = nil; nil->parent = nil;
    nil->isRed = false;
    root = nil;
}

treeElm* StringTree::findMin(treeElm *node){
    while(node->left != nil){
        node = node->left;
    }
    return node;
}

void StringTree::rbDelete(treeElm *node){
    treeElm *y; treeElm *x;
    y = node;
    bool y_original_colour = y->isRed;
    if(node->left == nil){
        x = node->right;
        StringTree::rbTransplant(node, node->right);
        delete node;
    }
    else if(node->right == nil){
        x = node->left;
        StringTree::rbTransplant(node, node->left);
        delete node;
    }
    else{
        y = StringTree::findMin(node->right);
        y_original_colour = y->isRed;
        x = y->right;
        if(y->parent == node){
            x->parent = y;
        }
        else{
            StringTree::rbTransplant(y, y->right);
            y->right = node->right;
            y->right->parent = y;
        }
        StringTree::rbTransplant(node,y);
        y->left = node->left;
        y->left->parent = y;
        y->isRed = node->isRed;
        delete node;
    }
    if(!y_original_colour){
        StringTree::rbPopFix(x);
    }
}

void StringTree::pop(string title){
    treeElm *temp; temp = root;
    while(temp != NULL){
        if(temp->title == title){
            StringTree::rbDelete(temp);
            return;
        }
        else if(isABigger(temp->title, title)){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
    if(temp == NULL){
        cout<<"String not found"<<endl;
    }
}

void StringTree::AcendingPrint(treeElm *node){
    if(node->left != nil){
        StringTree::AcendingPrint(node->left);
    }
    cout<<node->title<<endl;
    if(node->right != nil){
        StringTree::AcendingPrint(node->right);
    }
}

void StringTree::DecendingPrint(treeElm *node){
    if(node->right != nil){
        StringTree::DecendingPrint(node->right);
    }
    cout<<node->title<<endl;
    if(node->left != nil){
        StringTree::DecendingPrint(node->left);
    }
}

void StringTree::print(bool isAcending){
    if(isAcending){
        StringTree::AcendingPrint(root);
    }else{
        StringTree::DecendingPrint(root);
    }
}

void StringTree::push(std::string title, int data){
    treeElm *newNode; newNode = new treeElm(title, data);
    newNode->right = nil; newNode->left = nil; newNode->isRed = true; newNode->parent == nil;
    treeElm *child; treeElm *parent;
    child = root; parent = nil;
    while(child != nil){
        if(StringSorter::isABigger(child->title,newNode->title)){
            parent = child;
            child = parent->left;
        }else{
            parent = child;
            child = parent->right;
        }
    }
    if(child == nil){
        if(parent == nil){
            newNode->parent = nil;
            root = newNode;
            StringTree::rbPushFix(newNode);
        }else{
            if(StringSorter::isABigger(parent->title,newNode->title)){
                parent->left = newNode;
            }else{
                parent->right = newNode;
            }
            newNode->parent = parent;
            StringTree::rbPushFix(newNode);
        }
    }
}


void StringTree::rbPushFix(treeElm *node){
    node->right = nil; node->left = nil;
    node->isRed = true;
    while((node != root) && (node->parent->isRed == true)){
           if(node->parent == node->parent->parent->left){
               //cout<<"left Child"<<endl;
                treeElm *uncle = node->parent->parent->right;
                if(uncle->isRed){
                    node->parent->isRed = false;
                    uncle->isRed = false;
                    node->parent->parent->isRed = true;
                    node = node->parent->parent;
                }
                else{
                    if(node == node->parent->right){
                        node = node->parent;
                        StringTree::leftRotate(node);
                    }
                    node->parent->isRed = false;
                    node->parent->parent->isRed = true;
                    StringTree::rightRotate(node->parent->parent);
                }
            }
            else{
                //cout<<"Right Child"<<endl;
                treeElm *uncle = node->parent->parent->left;
                if(uncle->isRed){
                    node->parent->isRed = false;
                    uncle->isRed = false;
                    node->parent->parent->isRed = true;
                    node = node->parent->parent;
                }
                else{
                    if(node == node->parent->left){
                        node = node->parent;
                        StringTree::rightRotate(node);
                    }
                    node->parent->isRed = false;
                    node->parent->parent->isRed = true;
                    StringTree::leftRotate(node->parent->parent);
                }
            }
        }
    root->isRed = false;
}

void StringTree::rbPopFix(treeElm *x){
    while((x != root) && (x->isRed == false)){
        if(x == x->parent->left){
            treeElm *w;
            w = x->parent->right;
            if(w->isRed){
                w->isRed = false;
                x->parent->isRed = true;
                StringTree::leftRotate(x->parent);
                w = x->parent->right;
            }
            if((!w->left->isRed) && (!w->right->isRed)){
                w->isRed = true;
                x = x->parent;
            }
            else{
                if(!w->right->isRed){
                    w->left->isRed = false;
                    w->isRed = true;
                    StringTree::rightRotate(w);
                    w = x->parent->right;
                }
                w->isRed = x->parent->isRed;
                x->parent->isRed = false;
                w->right->isRed = false;
                StringTree::leftRotate(x->parent);
                x = root;

            }
        }else{
            treeElm *w;
            w = x->parent->left;
            if(w->isRed){
                w->isRed = false;
                x->parent->isRed = true;
                StringTree::rightRotate(x->parent);
                w = x->parent->left;
            }
            if((!w->left->isRed) && (!w->right->isRed)){
                w->isRed = true;
                x = x->parent;
            }
            else{
                if(!w->left->isRed){
                    w->right->isRed = false;
                    w->isRed = true;
                    StringTree::leftRotate(w);
                    w = x->parent->left;
                }
                w->isRed = x->parent->isRed;
                x->parent->isRed = false;
                w->left->isRed = false;
                StringTree::rightRotate(x->parent);
                x = root;

            }
        }
    }
    x->isRed = false;
}

void StringTree::rbTransplant(treeElm *u, treeElm *v){
    if(u->parent == nil){
        root = v;
    }
    else if(u == u->parent->left){
        u->parent->left = v;
    }
    else{
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void StringTree::rightRotate(treeElm *x){
    treeElm *y;
    y = x->left;
    x->left = y->right;
    if(y->right != nil){
        y->right->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == nil){
        root = y;
    }
    else if(x == (x->parent)->right){
        x->parent->right = y;
    }else{
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

void StringTree::leftRotate(treeElm *x){
    treeElm *y;
    y = x->right;
    x->right = y->left;
    if(y->left != nil){
        y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == nil){
        root = y;
    }
    else if(x == (x->parent)->left){
        x->parent->left = y;
    }else{
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

