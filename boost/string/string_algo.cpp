#include <string>
#include <iostream>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;

void upper_lower()
{
    cout << "============ upper_lower: ============" << endl;
    // to_lower, to_lower_copy
    // to_upper, to_upper_copy
    string str("I Don't Know.\n");
    cout << to_upper_copy(str);
    cout << str;
    to_lower(str);
    cout << str;
}

int main()
{
    upper_lower();

    return 0;
}
