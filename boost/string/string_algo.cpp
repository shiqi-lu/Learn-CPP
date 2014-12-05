#include <string>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/foreach.hpp>
#include <boost/format.hpp>
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

void predicate()
{
    string str("Power Bomb");
    assert(iends_with(str, "bomb"));
    assert(!ends_with(str, "bomb"));

    assert(starts_with(str, "Pow"));
    assert(istarts_with(str, "pOw"));

    assert(contains(str, "er"));
    assert(icontains(str, "Er"));

    string str2 = to_lower_copy(str);
    assert(iequals(str, str2));

    string str3("power suit");
    assert(ilexicographical_compare(str, str3));

    assert(all(str2.substr(0, 5), is_lower()));
}
/*
void compare()
{
    string str1("Samus"), str2("samus");
    
    // is_equal, is_iequal
    assert(!boost::is_equal()(str1, str2));
    
    // is_less, is_iless
    assert(boost::is_less()(str1, str2));

    //is_not_greater, is_not_igreater
    assert(boost::is_not_igreater()(str1, str2));
}
*/

void test_string_classify()
{
    // 搭配predicator使用
    // is_space: 字符是否为空格或制表符
    // is_alnum: 字符是否为字母和数字字符
    // is_alpha: 字符是否为字母
    // is_cntrl: 字符是否为控制字符
    // is_digit: 字符是否为十进制字符
    // is_graph: 字符是否为图形字符
    // is_lower: 字符是否为小写字符
    // is_print: 字符是否为可打印字符
    // is_punct: 字符是否为标点符号字符
    // is_upper: 字符是否为大写字符
    // is_xdigit: 字符是否为十六进制字符
    // is_any_of: 字符是否是参数字符序列中的任意字符
    // is_from_range: 字符是否位于指定区间内，即from <= ch <= to
}

void trim()
{
    cout << "============= trim: ==============" << endl;
    // trim_left, trim_right, trim
    // additional: _if, _copy, (trim_left_copy_if)
    format fmt("|%s|\n");
    string str = "  samus aran    ";
    cout << fmt % str;
    cout << fmt % trim_copy(str);
    cout << fmt % trim_left_copy(str);

    trim_right(str);
    cout << fmt % str;

    string str2 = "2012 Happy new Year!!!";
    cout << fmt % str2;
    cout << fmt % trim_left_copy_if(str2, is_digit());
    cout << fmt % trim_right_copy_if(str2, is_digit());
    cout << fmt % trim_copy_if(str2, is_punct() || is_digit() || is_space());
    cout << fmt % trim_copy_if(str2, is_any_of("2"));
}
/*
output:
============= trim: ==============
|  samus aran    |
|samus aran|
|samus aran    |
|  samus aran|
|2012 Happy new Year!!!|
| Happy new Year!!!|
|2012 Happy new Year!!!|
|Happy new Year|
|012 Happy new Year!!!|
*/

void find()
{
    cout << "============== find: ================" << endl;

    format fmt("|%s|.pos = %d\n");

    string str = "Long long ago, there was a king.";

    iterator_range<string::iterator> rge;

    // find_first, ifind_first, find_last, ifind_last
    rge = find_first(str, "long");
    cout << fmt % rge % (rge.begin() - str.begin());

    rge = ifind_first(str, "long");
    cout << fmt % rge % (rge.begin() - str.begin());

    // find_nth, ifind_nth
    rge =  find_nth(str, "ng", 2);
    cout << fmt % rge % (rge.begin() - str.begin());

    rge = find_head(str, 4);
    cout << fmt % rge % (rge.begin() - str.begin());

    rge = find_tail(str, 5);
    cout << fmt % rge % (rge.begin() - str.begin());

    rge = find_first(str, "samus");
    assert(rge.empty() && !rge);
/*
output:
============== find: ================
|long|.pos = 5
|Long|.pos = 0
|ng|.pos = 29
|Long|.pos = 0
|king.|.pos = 27
*/
}

void replace_erase()
{
    // replace/erase_first
    // replace/erase_last
    // replace/erase_nth
    // replace/erase_all
    // replace/erase_head
    // replace/erase_tail
    // additional: i, _copy,
    // erase_head and erase_tail: _copy
    cout << "============ replace_erase: ============" << endl;
    string str = "Samus beat the monster.\n";

    cout << str;

    cout << replace_first_copy(str, "Samus", "samus");

    replace_last(str, "beat", "kill");
    cout << str;

    replace_tail(str, 9, "ridley.\n");
    cout << str;

    cout << ierase_all_copy(str, "samus");
    cout << replace_nth_copy(str, "l" , 1, "L");
    cout << erase_tail_copy(str, 8);
    cout << endl;

/*
output:
============ replace_erase: ============
Samus beat the monster.
samus beat the monster.
Samus kill the monster.
Samus kill the ridley.
 kill the ridley.
Samus kilL the ridley.
Samus kill the
*/
}

void split()
{
    cout << "============ split: ==============" << endl;
    string str = "Samus,Link.Zelda::Mario-Luigi+zelda";

    deque<string> d;
    ifind_all(d, str, "zELDA");
    assert(d.size() == 2);
    BOOST_FOREACH(string x, d) {
        cout << "[" << x << "] ";
    }
    cout << endl;

    list<iterator_range<string::iterator> > l;
    split(l, str, is_any_of(",.:-+"));
    BOOST_FOREACH(iterator_range<string::iterator> rge, l) {
        cout << "[" << rge << "]";
    }
    cout << endl;

    l.clear();
    // 若有token_compress_on则两个连续的分割符被视为一个
    // token_compress_off
    split(l, str, is_any_of(".:-"), token_compress_on);
    BOOST_FOREACH(iterator_range<string::iterator> rge, l) {
    //for (auto rge : l) {
        cout << "[" << rge << "]";
    }
    cout << endl;

/*
output:
============ split: ==============
[Zelda] [zelda] 
[Samus][Link][Zelda][][Mario][Luigi][zelda]
[Samus,Link][Zelda][Mario][Luigi+zelda]
*/
}

int main()
{
    upper_lower();

    predicate();

    //compare();

    test_string_classify();

    trim();

    find();

    replace_erase();

    split();

    return 0;
}
