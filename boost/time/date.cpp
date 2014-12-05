// g++ date_time.cpp -I/root/dev/CPPEverything/include/
// /root/dev/CPPEverything/lib/libboost_date_time.a
#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>
//#define BOOST_DATE_TIME_SOURCE
using namespace boost::gregorian;
using namespace std;

void init_date()
{
    cout << "============ init date: =============" << endl;
    date d;
    date d1(2012, 4, 2);
    date d2(2033, May, 9);
    date d3(d2);

    cout << d2 << endl;

    assert(d3 == d2);
    assert(d1 < d2);

    date d4 = from_string("1992-12-9");
    date d5 = from_undelimited_string("2011118");

    cout << day_clock::local_day() << endl;
    cout << day_clock::universal_day() << endl << endl;

    date d6(neg_infin);
    date d7(pos_infin);
    date d8(not_a_date_time);
    date d9(max_date_time);
    date d10(min_date_time);
    cout << d6 << endl;
    cout << d7 << endl;
    cout << d8 << endl;
    cout << d9 << endl;
    cout << d10 << endl;

/*
output:
============ init date: =============
2033-May-09
2014-Dec-05
2014-Dec-05

-infinity
+infinity
not-a-date-time
9999-Dec-31
1400-Jan-01
*/
}

void visit_date()
{
    cout << "============ visit_date: ===========" << endl;
    date d(2010, 4, 1);
    assert(d.year() == 2010);
    assert(d.month() == 4);
    assert(d.day() == 1);

    date::ymd_type ymd = d.year_month_day();
    assert(ymd.year == 2010);
    assert(ymd.month == 4);
    assert(ymd.day == 1);

    cout << d.day_of_week() << endl;
    cout << d.day_of_year() << endl;
    cout << d.end_of_month() << endl;
    cout << d.week_number() << endl;

    assert(date(pos_infin).is_infinity());
    assert(date(pos_infin).is_pos_infinity());
    assert(date(neg_infin).is_neg_infinity());
    assert(date(not_a_date_time).is_not_a_date());
    assert(date(not_a_date_time).is_special());
    assert(!date(2010,10,1).is_special());

    cout << d << endl;
    cout << to_simple_string(d) << endl;
    cout << to_iso_string(d) << endl;
    cout << to_iso_extended_string(d) << endl;
/*
output:
============ visit_date: ===========
Thu
91
2010-Apr-30
13
2010-Apr-01
2010-Apr-01
20100401
2010-04-01
*/
}

void tm_date_convert()
{
    date d1(2012, 2, 1);
    tm t = to_tm(d1);
    assert(t.tm_hour == 0 && t.tm_min == 0 && t.tm_sec == 0 && t.tm_isdst == -1);
    assert(t.tm_year == 112 && t.tm_mday == 1 && t.tm_mon == 1);

    date d2 = date_from_tm(t);
    assert(d1 == d2);
}

int main()
{
    init_date();

    visit_date();

    tm_date_convert();

    return 0;
}
