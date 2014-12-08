#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void print_myvt(string & tmp)
{
    cout << "the city is : " << tmp << endl;
}

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
    // not recommend
    for (int i = 0; i < 4; ++i) {
        cout << myvt.at(i) << endl;
    }
    for_each(myvt.begin(), myvt.end(), print_myvt);
    cout << "size is " << myvt.size() << endl;
    cout << "capacity is " << myvt.capacity() << endl;
    cout << "maxsize is " << myvt.max_size() << endl;
    myvt.resize(7);    //重置大小
    cout << "resize: 7" << endl;
    cout << "size is " << myvt.size() << endl;
    cout << "capacity is " << myvt.capacity() << endl;
    for (it = myvt.begin(); it != myvt.end(); ++it) {
        if (*it == "") {
            cout << "*********" << endl;
            continue;
        }
        cout << *it << endl;
    }
    cout << endl <<  "empty: " << endl;
    string tmp;
    while(!myvt.empty()) {
        tmp = myvt.back();
        cout << tmp << endl;
        myvt.pop_back();
    }
    if (!myvt.empty()) {
        myvt.clear();
    }
/*
output:
=========== init_vector: ===========
1.Beijing City.
2.Tianjin City.
3.Shanghai City.
4.Chongqing City.
1.Beijing City.
2.Tianjin City.
3.Shanghai City.
4.Chongqing City.
the city is : 1.Beijing City.
the city is : 2.Tianjin City.
the city is : 3.Shanghai City.
the city is : 4.Chongqing City.
size is 4
capacity is 4
maxsize is 2305843009213693951
resize: 7
size is 7
capacity is 8
1.Beijing City.
2.Tianjin City.
3.Shanghai City.
4.Chongqing City.
*********
*********
*********

empty: 



4.Chongqing City.
3.Shanghai City.
2.Tianjin City.
1.Beijing City.
*/
}



int main()
{
    init_vector();   

    return 0;
}
