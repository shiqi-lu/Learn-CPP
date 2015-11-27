#include "addval.hpp"
#include <iostream>

void call_addValue()
{
    addValue<int, 5>(42);
}

template <typename IT, typename OP>
void transform(IT beg, IT end, IT to, OP op)
{
    while (beg != end) {
        *to++ = op(*beg++);
    }
}

int main()
{
    call_addValue();
    int m[] = {1, 2, 3, 4, 5, 6};
    transform(m, m + 6, m, addValue<int, 5>);
    for (int i = 0; i < 6; ++i) {
        std::cout << m[i] << " ";
    }
    std::cout << std::endl;
}
