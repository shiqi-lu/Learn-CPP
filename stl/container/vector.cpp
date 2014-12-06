#include <iostream>
#include <string>
#include <vector>
using namespace std;

void init_vector()
{
    cout << "=========== init_vector: ===========" << endl;
    vector<string> myvt;
    // optional
    myvt.reserve(4);
    myvt.push_back("1.Beijing City.");
    myvt.push_back("2.Tianjin City.");
    myvt.push_back("3.Shanghai City.");
    myvt.push_back("4.Chongqing City.");
    vector<string>::iterator it;
    for (it = myvt.begin(); it != myvt.end(); ++it) {
        cout << *it << endl;
    }
    cout << "size is " << myvt.size() << endl;
    cout << "capacity is " << myvt.capacity() << endl;
    cout << "maxsize is " << myvt.max_size() << endl;
    myvt.resize(10);    //重置大小
    cout << "resize: 10" << endl;
    cout << "size is " << myvt.size() << endl;
    cout << "capacity is " << myvt.capacity() << endl;
    for (it = myvt.begin(); it != myvt.end(); ++it) {
        if (*it == "") {
            cout << "*********" << endl;
        }
        cout << *it << endl;
    }
/*
output
=========== init_vector: ===========
1.Beijing City.
2.Tianjin City.
3.Shanghai City.
4.Chongqing City.
size is 4
capacity is 4
maxsize is 2305843009213693951
resize: 10
size is 10
capacity is 10
1.Beijing City.
2.Tianjin City.
3.Shanghai City.
4.Chongqing City.
*********

*********

*********

*********

*********

*********
*/
}

int main()
{
    init_vector();   

    return 0;
}
