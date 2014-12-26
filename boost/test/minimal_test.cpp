#include <boost/test/minimal.hpp>
#include <boost/format.hpp>
#include <iostream>

int test_main(int argc, char * argv[])
{
    boost::format fmt("%d-%d");

    BOOST_CHECK(fmt.size() != 0);
    fmt % 12 % 34;
    BOOST_REQUIRE(fmt.str() == "12-34");

    BOOST_ERROR("show an error message");

    fmt.clear();
    fmt % 12;
    try {
        std::cout << fmt;
    } catch (...) {
        BOOST_FAIL("fatal error, test terminated!");
    }

    return 0;
}
/*
output:
minimal_test.cpp(13): show an error message in function: 'int test_main(int, char**)'
minimal_test.cpp(20): fatal error, test terminated! in function: 'int test_main(int, char**)'

**** 2 errors detected
*/
