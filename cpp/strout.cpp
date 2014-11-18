//strout.cpp -- incore formatting (output)
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    using namespace std;
    stringstream outstr;

    string hdisk;
    cout << "What's the name of your hard disk? ";
    getline(cin, hdisk);
    int cap;
    cout << "What's its capacity in GB? ";
    cin >> cap;
    outstr << "The hard disk " << hdisk << " has a capacity of "
           << cap << " gigabytes.\n";
    string result;
    getline(outstr, result);
    cout << result;
    outstr.clear();
    outstr << "another test";
    getline(outstr, result);
    cout << result;
    


    return 0;
}
