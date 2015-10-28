#include <iostream>
#include <algorithm>
#include "Composite.h"

Composite::~Composite()
{
    std::list<Component *>::iterator iter1, iter2, temp;
    for (iter1 = ListOfComponent_.begin(), iter2 = ListOfComponent_.end();
         iter1 != iter2;) {
        temp = iter1;
        ++iter1;
        delete (*temp);
    }
}

void Composite::Add(Component * pChild)
{
    ListOfComponent_.push_back(pChild);
}

void Composite::Remove(Component * pChild)
{
    std::list<Component *>::iterator iter;

    iter = find(ListOfComponent_.begin(), ListOfComponent_.end(), pChild);

    if (ListOfComponent_.end() != iter) {
        ListOfComponent_.erase(iter);
    }
}

Component * Composite::GetChild(int nIndex)
{
    if (nIndex <= 0 || nIndex > ListOfComponent_.size()) {
        return NULL;
    }

    std::list<Component *>::iterator iter1, iter2;
    int i;
    for (i = 1, iter1 = ListOfComponent_.begin(), iter2 = ListOfComponent_.end();
         iter1 != iter2; ++iter1, ++i) {
        if (i == nIndex) {
            break;
        }
    }
    return * iter1;
}

void Composite::Operation()
{
    std::cout << "Operation by Composite" << std::endl;

    std::list<Component *>::iterator iter1, iter2;

    for (iter1 = ListOfComponent_.begin(), iter2 = ListOfComponent_.end();
         iter1 != iter2; ++iter1) {
        (*iter1)->Operation();
    }
}


