#ifndef STUDENTRECORE_H_
#define STUDENTRECORE_H_

#include <string>
#include <iostream>

struct studentRecord
{
    int score;
    std::string * name;
    operator int() const { return score; }
};

std::ostream & operator<<(std::ostream & out, const studentRecord & x)
{
    out << x.score << ' ' << *x.name << std::endl;
    return out;
}

#endif
