//#define BOOST_DISABLE_ASSERTS
#include <cassert>
#include <string>
#include <iostream>
#include <boost/assert.hpp>

double msg(int x)
{
    BOOST_ASSERT(x != 0 && "divided by zero");
    return 1.0 / x;
}

double forbid(int x)
{
    //#define BOOST_DISABLE_ASSERTS
    BOOST_ASSERT(x != 0 && "divided by zero");
    std::cout << "after BOOST_ASSERT" << std::endl;

    assert(x != 0 && "divided by zero");
    std::cout << "after" << std::endl;

    return 1.0 / x;
}

int main()
{
    BOOST_ASSERT(16 == 0x10);
    //BOOST_ASSERT(std::string().size() == 1);
    
    //msg(0);

    //forbid(0);

    return 0;
}
