#ifndef STRINGHASH_H_INCLUDED
#define STRINGHASH_H_INCLUDED

struct hashElm{
    std::string title;
    hashElm *next;

    hashElm();
    hashElm(std::string in_string){
        title = in_string;
    }
};

class StringHash:public StringSorter{
public:
    StringHash(int);
    ~StringHash();
    void push(std::string);
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
