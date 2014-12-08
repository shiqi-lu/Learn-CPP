//g++ -I$CPPET/include tokenizer.cpp --std=c++11 && ./a.out
#include <string>
#include <iostream>
#include <boost/tokenizer.hpp>
#include <boost/foreach.hpp>
#include <boost/typeof/typeof.hpp>
using namespace std;
using namespace boost;

void demo()
{
    cout << "========= demo: ============" << endl;
    string str("Link raise the master-sword.");

    tokenizer<> tok(str);

    BOOST_FOREACH(auto x, tok) {
        cout << "[" << x << "]";
    }
    cout << endl;

/*
output:
[Link][raise][the][master][sword]
*/
}

template<typename T>
void print(T & tok)
{
    for (auto & x : tok) {
        cout << "[" << x << "]";
    }
    cout << endl;
}

void tok_char_separator()
{
    cout << "========== char_separator: =============" << endl;
    char * str = (char *)"Link ;; <master-sword> zelda";

    char_separator<char> sep;

    tokenizer<char_separator<char>, char*> tok(str, str + strlen(str), sep);
    print(tok);

    tok.assign(str, str + strlen(str), char_separator<char>(" ;-", "<>"));
    print(tok);

    tok.assign(str, str + strlen(str), char_separator<char>(" ;-<>", "", keep_empty_tokens));
    print(tok);

/*
output:
========== char_separator: =============
[Link][;][;][<][master][-][sword][>][zelda]
[Link][<][master][sword][>][zelda]
[Link][][][][][master][sword][][zelda]
*/
}


int main()
{
    demo();

    tok_char_separator();

    return 0;
}
