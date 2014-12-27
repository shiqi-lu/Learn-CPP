//g++ execution_monitor.cpp -I$CPPET/include
//$CPPET/lib/libboost_test_exec_monitor.a && ./a.out 
#include <iostream>
#include <boost/test/execution_monitor.hpp>

int f()
{
    std::cout << "f execute." << std::endl;
    throw "a error accured";
    return 10;
}

int main()
{
    boost::execution_monitor em;

    try {
        em.execute(boost::unit_test::callback0<int>(f));
    } catch (boost::execution_exception & e) {
        std::cout << "execution_exception" << std::endl;
        std::cout << e.what().begin() << std::endl;
    }

    return 0;
}
/*output:
f execute.
execution_exception
C string: a error accured
*/
