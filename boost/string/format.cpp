#include <iostream>
#include <iomanip>
#include <boost/format.hpp>
using namespace boost;
using namespace std;

int main()
{
    cout << format("%s: %d + %d = %d\n") % "sum" % 1 % 2 % (1+2);

    format fmt("(%1% + %2%) * %2% = %3% \n");
    fmt % 2 % 5;
    fmt % ((2+5) * 5);
    cout << fmt.str();
    cout << fmt.size() << endl << endl;
    
    //format fmt1("%05d\n%-8.3f\n% 10s\n%05X\n");
    format fmt1("%|05d|\n%|-8.3f|\n%| 10s|\n%|05X|\n");
    cout << fmt1 % 62 % 2.236 % "12346" % 48;

    // use const can boost speed
    const format fmt2("%|10d|\n%|20.8f|\n%|010X|\n%|10.5e|\n");
    cout << format(fmt2) % 62 % 2.236 % 255 % 0.618;

    format fmt3("%1% %2% %3% %2% %1% \n");
    cout << fmt3 % 1 % 2 % 3;
    fmt3.bind_arg(2, 10); // bind the second parameter to 10
    cout << fmt3 % 8 % 20;  // enter next two number
    fmt3.clear();           // clear the cache except the second
    cout << fmt3 % boost::io::group(showbase,oct,111) % 333;
    fmt3.clear_binds();     // clear all binding
    fmt3.modify_item(1, boost::io::group(hex, right, showbase, setw(8), setfill('*')));
    cout << fmt3 % 49 % 20 % 100;

    return 0;
}
/*
output:
sum: 1 + 2 = 3
(2 + 5) * 5 = 35 
18

00062
2.236   
     12346
00030
        62
          2.23600000
00000000FF
6.18000e-01
1 2 3 2 1 
8 10 20 10 8 
0157 10 333 10 0157 
****0x31 20 100 20 49
*/
