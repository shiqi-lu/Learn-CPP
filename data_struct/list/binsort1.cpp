#include <iostream>
#include "studentRecord1.h"
#include "chainWithIterator.h"
#include "myExceptions.h"

void binSort(chain<studentRecord> & theChain, int range)
{
    chain<studentRecord> * bin;
    bin = new chain<studentRecord> [range + 1];

    int numberOfElements = theChain.size();
    for (int i = 0; i < numberOfElements; ++i) {
        studentRecord x = theChain.get(0);
        theChain.erase(0);
        bin[x.score].insert(0, x);
    }

    for (int j = range; j >= 0; --j) {
        while (!bin[j].empty()) {
            studentRecord x = bin[j].get(0);
            bin[j].erase(0);
            theChain.insert(0, x);
        }
    }

    delete [] bin;
}

int main()
{
    studentRecord s;
    chain<studentRecord> c;
    for (int i = 1; i <= 20; ++i) {
        s.score = i / 2;
        s.name = new std::string(s.score, 'a');
        c.insert(0, s);
    }
    std::cout << "The unsorted chain is" << std::endl;
    std::cout << "  " << c << std::endl;
    binSort(c, 10);
    std::cout << "The sorted chain is " << std::endl;
    std::cout << "  " << c << std::endl;
}
/*
The unsorted chain is
  10 aaaaaaaaaa
 9 aaaaaaaaa
 9 aaaaaaaaa
 8 aaaaaaaa
 8 aaaaaaaa
 7 aaaaaaa
 7 aaaaaaa
 6 aaaaaa
 6 aaaaaa
 5 aaaaa
 5 aaaaa
 4 aaaa
 4 aaaa
 3 aaa
 3 aaa
 2 aa
 2 aa
 1 a
 1 a
 0

The sorted chain is
  0
 1 a
 1 a
 2 aa
 2 aa
 3 aaa
 3 aaa
 4 aaaa
 4 aaaa
 5 aaaaa
 5 aaaaa
 6 aaaaaa
 6 aaaaaa
 7 aaaaaaa
 7 aaaaaaa
 8 aaaaaaaa
 8 aaaaaaaa
 9 aaaaaaaaa
 9 aaaaaaaaa
 10 aaaaaaaaaa
*/
