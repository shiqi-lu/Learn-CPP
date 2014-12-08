//  g++ lexical_cast.cpp -I/e/dayu/CPPEverything/include/ && ./a.exe
#include <string>
#include <iostream>
#include <boost/lexical_cast.hpp>
using namespace boost;
using namespace std;

// this function can test 
// whether the number is valid
template <typename T>
bool num_valid(const string & str)
{
    bool done = false;
    try {
        lexical_cast<T>(str);
        done = true;
    } catch (const bad_lexical_cast &) {
        done = false;
    }
    return done;
}

int main()
{
    cout << "========= lexical_cast in boost: =========" << endl; 
    int x = lexical_cast<int>("100");
    long y = lexical_cast<long>("20000");
    float pai = lexical_cast<float>("3.14159e5");
    double e = lexical_cast<double>("2.71828");
    
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "pai = " << pai << endl;
    cout << "e = " << e << endl;

    cout << lexical_cast<string>(456) << endl;
    cout << lexical_cast<string>(0.618) << endl;
    cout << lexical_cast<string>(0x10) << endl;

    try {
        cout << lexical_cast<int>("0xx100");
        cout << lexical_cast<double>("HelloWorld");
        cout << lexical_cast<long>("1000L");
        cout << lexical_cast<bool>("false") << endl;
    } catch (const bad_lexical_cast & e) {
        cout << "Error: " << e.what() << endl;
    }

    assert(num_valid<double>("3.14"));
    assert(!num_valid<int>("3.14"));

    return 0;
}
