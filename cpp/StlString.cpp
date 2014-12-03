#include <iostream>
#include <string>

using namespace std;
void constructor()
{
    cout << "=========== Constructor: =========" << endl; 
    string str("12345678");
    char ch[] = "abcdefgh";
    string str_0;               // declare an empty string
    string str_1(str);          // copy all string in str
    string str_2(str, 2 ,5);    // 34567
    string str_3(ch, 5);        // abcde
    string str_4(5, 'X');       // XXXXX
    string str_5(str.begin(), str.end());   // copy str to str_5
    cout << str << endl;
    cout << str_0 << endl;
    cout << str_1 << endl;
    cout << str_2 << endl;
    cout << str_3 << endl;
    cout << str_4 << endl;
    cout << str_5 << endl;
}

void capacity()
{
    cout << "======== Capacity: =========" << endl;
    string str("12345678");
    string str_custom;

    str_custom.reserve(30);
    str_custom = str;
    int size = str_custom.size();           // 8
    int length = str_custom.length();       // 8
    unsigned long maxsize = str_custom.max_size();    // 1073741820
    int capacity = str_custom.capacity();   // 8
    bool empty = str.empty();               // test whether the string is empty
    cout << "size = " << size << endl;
    cout << "length = " << length << endl;
    cout << "maxsize = " << maxsize << endl;
    cout << "capacity = " << capacity << endl;
    cout << "empty = " << empty << endl;
    str.clear();        // clear the string
    cout << "after clear :" << str << endl;
}

void element_access()
{
    cout << "========= element access: =======" << endl;
    const string cS("constString");
    string s("abcde");
    char temp = 0;
    char temp1 = 0;
    char temp2 = 0;
    char temp3 = 0;
    temp = s[2];            // c
    temp1 = s.at(2);        // c
    temp2 = s[s.length()];  // nothing
    temp3 = cS[cS.length()];// nothing
    cout << "\"" << temp << temp1 << temp2 << temp3 << "\"" << endl;
}

void string_compare()
{
   cout << "========= compare: ========" << endl;
   string A("aBcdef");
   string B("AbcdEf");
   string C("123456");
   string D("123dfg");

   // if s is before s1, return negative number
   int m = A.compare(B);
   int n = A.compare(1, 5, B);          // compare "Bcdef" and "AbcdEf"
   int p = A.compare(1, 5, B, 4, 2);    // compare "Bcdef" and "Ef"
   int q = C.compare(0, 3, D, 0, 3);    // compare "123 and "123"
   cout << "m=" << m << ", n=" << n 
        << ", p=" << p << ", q=" << q << endl;
   // m=1, n=1, p=-1, q=0
}

int main() 
{
    constructor();

    capacity();

    element_access();

    string_compare();

    return 0;
}
