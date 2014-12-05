#include <iostream>
#include <vector>
#include <string>
#include <boost/smart_ptr.hpp>
using namespace boost;
using namespace std;

struct posix_file
{
    posix_file(const char * file_name)
    {
        cout << "open file: " << file_name << endl;
    }
    ~posix_file()
    {
        cout << "close file" << endl;
    }
};

void boost_scoped_ptr()
{
    cout << "============== scoped_ptr: =============" << endl;
    scoped_ptr<string> sp(new string("text"));
    cout << *sp << endl;
    cout << sp->size() << endl;

    scoped_ptr<int> p(new int);

    if (p) {
        *p = 100;
        cout << *p << endl;
    }
    p.reset();

    assert(p == 0);
    if (!p) {
        cout << "scoped_ptr == null" << endl;
    }
    scoped_ptr<posix_file> fp (new posix_file("/tmp/a.txt"));

/*
output:
============== scoped_ptr: =============
text
4
100
scoped_ptr == null
open file: /tmp/a.txt
close file
*/
}

// not recommend to use
void boost_scoped_array()
{
    scoped_array<int> sap(new int [100]);
    sap[0] = 10;

    int * arr = new int [100];
    scoped_array<int> sa(arr);
    fill_n(&sa[0], 100, 5);
    sa[10] = sa[20] + sa[30];
}

void boost_shared_ptr()
{
    shared_ptr<int> spi(new int);
    assert(spi);
    *spi = 253;

    shared_ptr<string> sps(new string("smart"));
    assert(sps->size() == 5);

    shared_ptr<int> sp(new int(10));
    assert(sp.unique());

    shared_ptr<int> sp2 = sp;

    assert(sp == sp2 && sp.use_count() == 2);

    *sp2 = 100;
    assert(*sp == 100);
    sp.reset();
    assert(!sp);
}

class shared
{
private:
    shared_ptr<int> p;
public:
    shared(shared_ptr<int> p_):p(p_) {}
    void print()
    {
        cout << "count:" << p.use_count()
             << ",v =" << *p << endl;
    }
};

void print_func(shared_ptr<int> p)
{
    cout << "count:" << p.use_count()
         << ", v=" << *p << endl;
}

void boost_shared_ptr_class()
{
    cout << "======= shared_ptr_class: ========" << endl;
    shared_ptr<int> p (new int(100));
    shared s1(p), s2(p);

    s1.print();
    s2.print();

    *p = 20;
    print_func(p);

    s1.print();

/*
output:
======= shared_ptr_class: ========
count:3,v =100
count:3,v =100
count:4, v=20
count:3,v =20
*/
}

void boost_stl_shared_ptr()
{
    cout << "========= stl_shared_ptr: =============" << endl;
    typedef vector<shared_ptr<int> > vs;
    vs v(10);

    int i = 0;
    for (vs::iterator pos = v.begin(); pos != v.end(); ++pos) {
        (*pos) = make_shared<int>(++i);
        cout << *(*pos) << ", ";
    }
    cout << endl;

    shared_ptr<int> p = v[9];
    *p = 100;
    cout << *v[9] << endl;
 
/*
output:
========= stl_shared_ptr: =============
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
100
*/
}

void boost_shared_array()
{
    int * p = new int[100];
    shared_array<int> sa(p);
    shared_array<int> sa2 = sa;

    sa[0] = 10;
    assert(sa2[0] == 10);
}

void boost_weak_ptr()
{
    shared_ptr<int> sp(new int(10));
    assert(sp.use_count() == 1);

    weak_ptr<int> wp(sp);
    assert(wp.use_count() == 1);

    if (!wp.expired()) {
        shared_ptr<int> sp2 = wp.lock();
        *sp2 = 100;
        assert(wp.use_count() == 2);
    }
    assert(wp.use_count() == 1);
    sp.reset();
    assert(wp.expired());
    assert(!wp.lock());
}

int main()
{
    boost_scoped_ptr();

    boost_scoped_array();

    boost_shared_ptr();

    boost_shared_ptr_class();

    boost_stl_shared_ptr();

    boost_shared_array();

    boost_weak_ptr();

    return 0;
}
