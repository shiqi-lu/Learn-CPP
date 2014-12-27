// g++ test_case.cpp -I$CPPET/include $CPPET/lib/libboost_unit_test_framework.a
// && ./a.out
#define BOOST_TEST_MAIN
//#define BOOST_TEST_INCLUDED
#include <boost/test/unit_test.hpp>
#include <boost/smart_ptr.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE(s_smart_ptr)

BOOST_AUTO_TEST_CASE(t_scoped_ptr)
{
    boost::scoped_ptr<int> p (new int(874));
    BOOST_CHECK(p);
    BOOST_CHECK_EQUAL(*p, 874);

    p.reset();
    BOOST_CHECK(p == 0);
}

BOOST_AUTO_TEST_CASE(t_shared_ptr)
{
    boost::shared_ptr<int> p (new int(100));

    BOOST_CHECK(p);
    BOOST_CHECK_EQUAL(*p, 100);
    BOOST_CHECK_EQUAL(p.use_count(), 1);

    boost::shared_ptr<int> p2 = p;
    BOOST_CHECK_EQUAL(p, p2);
    BOOST_CHECK_EQUAL(p2.use_count(), 2);

    *p2 = 255;
    BOOST_CHECK_EQUAL(*p, 255);
    BOOST_CHECK_GT(*p, 200);
}

BOOST_AUTO_TEST_SUITE_END()

/*output:
Running 2 test cases...

*** No errors detected
*/
