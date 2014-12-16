//g++ thread.cpp -I$CPPET/include $CPPET/lib/libboost_thread.a
//$CPPET/lib/libboost_system.a -lpthread
//#define BOOST_ALL_NO_LIB
#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/thread.hpp>

void hello()
{
    std::cout << "Hello world, I'm a thread!" << std::endl;
}

void name(const std::string & name)
{
    std::cout << "this name is: " << name << std::endl;
}

int main()
{
    boost::thread thrd1(&hello);
    boost::thread thrd2(boost::bind(name, "jone"));
    thrd1.join();
    thrd2.join();

    return 0;
}
