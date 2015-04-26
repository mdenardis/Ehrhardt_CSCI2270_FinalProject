#include <iostream>
#include "StringSorter.h"
#include "StringTree.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;


void StringTree::rbPushFix(treeElm *node){
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
                    //cout<<"red"<<endl;
                    node->parent->isRed = false;
                    uncle->isRed = false;
                    node->parent->parent->isRed = true;
                    node = node->parent->parent;
                }
                else{
                    //cout<<"black"<<endl;
                    if(node == node->parent->left){
                        //cout<<"yes?"<<endl;
                        node = node->parent;
                        //cout<<"please?"<<endl;
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

StringTree::~StringTree(){}

StringTree::StringTree(){}
