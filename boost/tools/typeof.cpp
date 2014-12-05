#include <vector>
#include <string>
#include <boost/typeof/typeof.hpp>
using namespace std;

vector<string> func()
{
    vector<string> v (10);
    return v;
}

void boost_auto()
{
    BOOST_TYPEOF(2.0 * 3) x = 2.0 * 3;      // double
    BOOST_AUTO(y, 2 + 3);                   // int

    BOOST_AUTO(a, new double [20]);         // double *
    BOOST_AUTO(p, make_pair(1, "string"));  // pair<int, const char*>

    BOOST_AUTO(v, func());                  // vector<string>

/******
 * equals:
 *
 * decltype(2.0 * 3) x = 2.0 * 3;
 * auto y = 2 + 3;
 *
 * auto a = new_double[20];
 * auto p = make_pair(1, "string");
 *
 * auto v = func();
 *
 * ***/
}

int main()
{
    boost_auto();

    return 0;
}
