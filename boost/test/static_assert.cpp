
#include <iostream>
#include <boost/static_assert.hpp>

// BOOST_STATIC_ASSERT(expr)
// BOOST_STATIC_MSG(expr, msg)

template<typename T>
T my_min(T a, T b)
{
    BOOST_STATIC_ASSERT(sizeof(T) < sizeof(int));
    return a < b? a : b;
}

int main()
{
    std::cout << my_min((short)1, (short)3);
    std::cout << my_min(1L, 3L);

    return 0;
}
