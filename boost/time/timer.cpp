#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
//#include <boost/timer.hpp>
#include <boost/progress.hpp>
#include <boost/foreach.hpp>
using namespace std;
using namespace boost;

// #include <boost/timer.hpp>
void boost_timer()
{
    cout << "=================== timer: =============" << endl;
    boost::timer t;

    cout << "max timespan: "
         << t.elapsed_max() / 3600 << "h" << endl;
    cout << "min timespan: "
         << t.elapsed_min() << "s" << endl;
    cout << "now time elapsed: " 
         << t.elapsed() << "s" << endl; 

    // reset time:
    // t.restart()
/*
max timespan: 2.56205e+09h
min timespan: 1e-06s
now time elapsed: 0s
*/
}

// #include <boost/progress.hpp>
// 继承timer,析构时自动输出时间
void boost_progress_timer()
{
    cout << "================ progress_timer: =============" << endl;
    {
        boost::progress_timer t;
    }
    {
        boost::progress_timer t;
    }
    stringstream ss;
    {
        progress_timer t(ss);
    }
    cout << ss.str();
/*
output:
0.00 s

0.00 s

0.00 s
*/
}

void boost_progress_display()
{
    cout << "============= prgress_display: ===========" << endl;
    vector<string> v(10000000);
    ofstream fs("./test.txt");

    progress_display pd(v.size());
    BOOST_FOREACH(string & x , v) {
        fs << x << endl;
        ++pd;
    }
/*
output:
0%   10   20   30   40   50   60   70   80   90   100%
|----|----|----|----|----|----|----|----|----|----|
***************************************************
*/
}

int main()
{
    boost_timer();

    boost_progress_timer();

    boost_progress_display();

    return 0;
}
