#ifndef STRINGTREE_H_INCLUDED
#define STRINGTREE_H_INCLUDED

struct treeElm{
    std::string title;
    int data;
    bool isRed;
    treeElm *left;
    treeElm *right;

    treeElm(){}

    treeElm(std::string in_string, int in_int){
        title = in_string;
        data = in_int;
    }
};

class StringTree: public StringSorter{
public:
    void push(std::string, int);
    void pop(std::string);
    void searchString(std::string);
    void print();
    void print(bool);
private:
    void rbPushFix(treeElm*);
    void rbPopFix(treeElm*);
    void rbTransplant(treeElm*, treeElm*);
    void leftRotate(treeElm*);
    void rightRotate(treeElm*);
    treeElm *root;
    treeElm *nil;

};

#endif // STRINGTREE_H_INCLUDED
