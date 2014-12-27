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
/*
 * BOOST_CHECK(predicate): 断言测试通过，如不通过不影响程序执行
 * BOOST_REQUIRE(predicate): 要求测试必须通过，否则程序停止执行
 * BOOST_ERROR(message): 给出一个错误信息，程序继续执行
 * BOOST_FAIL(message): 给出一个错误信息，程序终止执行
