#define BOOST_TEST_MODULE GLOBAL_FIXTUREOOO
//#define BOOST_TEST_MAIN

#include <iostream>
#include <vector>
#include <boost/test/unit_test.hpp>
#include <boost/assign.hpp>

struct global_fixture
{
    global_fixture()
    {
        std::cout << ("global setup\n");
    }
    ~global_fixture()
    {
        std::cout << ("global teardown\n");
    }
};

BOOST_GLOBAL_FIXTURE(global_fixture);

struct assign_fixture
{
    assign_fixture()
    {
        std::cout << ("suit setup\n");
    }
    ~assign_fixture()
    {
        std::cout << ("suit teardown\n");
    }
    std::vector<int> v;
};

BOOST_FIXTURE_TEST_SUITE(s_assign, assign_fixture)

BOOST_AUTO_TEST_CASE(t_assign1)
{
    using namespace boost::assign;

    v += 1,2,3,4;
    BOOST_CHECK_EQUAL(v.size(), 4);
    BOOST_CHECK_EQUAL(v[2], 3);
}

BOOST_AUTO_TEST_CASE(t_assign2)
{
    using namespace boost::assign;

    push_back(v)(10)(20)(30);

    BOOST_CHECK_EQUAL(v.empty(), false);
    BOOST_CHECK_LT(v[0], v[1]);
}

BOOST_AUTO_TEST_SUITE_END()

/* output:
global setup
Running 2 test cases...
suit setup
suit teardown
suit setup
suit teardown
global teardown

*** No errors detected
*/
