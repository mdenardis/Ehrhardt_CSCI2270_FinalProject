#ifndef STRINGSORTER_H_INCLUDED
#define STRINGSORTER_H_INCLUDED
#include <vector>
#include <string>

class StringSorter{
public:
    static void sortAlphabetically(std::vector<std::string> &stringList, bool isAscending);
private:
    static bool isABigger(std::string a, std::string b);

};

#endif // STRINGSORTER_H_INCLUDED
