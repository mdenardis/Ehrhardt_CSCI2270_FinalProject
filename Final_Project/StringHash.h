#ifndef STRINGHASH_H_INCLUDED
#define STRINGHASH_H_INCLUDED

struct hashElm{
    std::string title;
    hashElm *next;
    int data;

    hashElm();
    hashElm(std::string in_string, int in_int){
        title = in_string;
        data = in_int;
    }
};

class StringHash:public StringSorter{
public:
    StringHash(int);
    StringHash();
    ~StringHash();
    void push(std::string, int);
    void pop(std::string);
    void print();
    void print(bool);
    std::string getString(std::string);
private:
    hashElm **hashTable;
    int hashSum(std::string);
    int hashSize;
};


#endif // STRINGHASH_H_INCLUDED
