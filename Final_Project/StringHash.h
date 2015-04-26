#ifndef STRINGHASH_H_INCLUDED
#define STRINGHASH_H_INCLUDED

struct hashElm{
    std::string value;
    hashElm *next;

    hashElm();
    hashElm(std::string in_string){
        value = in_string;
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
private:
    hashElm **hashTable;
    int hashSum(std::string);
    int hashSize;
};

#endif // STRINGHASH_H_INCLUDED
