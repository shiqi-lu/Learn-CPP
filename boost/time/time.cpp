// g++ time.cpp -I/root/dev/CPPEverything/include/
// /root/dev/CPPEverything/lib/libboost_date_time.a && ./a.out
#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
//#include <boost/date_time/gregorian/gregorian.hpp>
using namespace std;

void boost_time_duration()
{
    using namespace boost::posix_time;
    cout << "=========== time_duration: =============" << endl;
    // 1hour, 10min, 30sec, 1000millionsec
    time_duration td(1, 10, 30, 1000);
    time_duration td1(1, 60, 60, 1000*1000*6 + 1000);

    hours h(1);
    minutes m(10);
    seconds s(30);
    millisec ms(1);

    time_duration td2 = h + m + s + ms;
    time_duration td3 = hours(2) + seconds(10);
    time_duration td4 = duration_from_string("1:10:30:001");
    cout << td << endl;
    cout << td.hours() << ":" << td.minutes() << ":" << td.seconds() << endl;
    cout << td.total_seconds() << endl;
    cout << td.total_milliseconds() << endl;
    cout << td.total_microseconds() << endl;
    // fractional_seconds return millionseconds in Long type
    cout << td.fractional_seconds() << endl;

    hours h1(-10);
    assert(h1.is_negative());
    time_duration h2 = h1.invert_sign();
    assert(!h2.is_negative() && h2.hours() == 10);

    time_duration td5(not_a_date_time);
    assert(td5.is_special() && td5.is_not_a_date_time());

    time_duration td6(neg_infin);
    assert(td6.is_negative() && td6.is_neg_infinity());

    time_duration td7 = hours(1);
    time_duration td8 = hours(2) + minutes(30);
    assert(td7 < td8);
    assert((td7 + td8).hours() == 3);
    assert((td7 - td8).is_negative());
    assert(td7 * 5 == td8 * 2);
    assert((td7 / 2).minutes() == td8.minutes());

    cout << to_simple_string(td) << endl;
    cout << to_iso_string(td) << endl;
/*
output:
=========== time_duration: =============
01:10:30.001000
1:10:30
4230
4230001
4230001000
1000
01:10:30.001000
011030.001000
*/
}

void boost_ptime()
{
    using namespace boost::posix_time;
    using namespace boost::gregorian;
    cout << "============== ptime: =============" << endl;
    ptime p(date(2010,3,5), hours(1));
    ptime p1 = time_from_string("2010-3-5 01:00:00");
    ptime p2 = from_iso_string("20100305T0100000");

    ptime p3 = second_clock::local_time();
    ptime p4 = microsec_clock::universal_time();
    cout << p3 << endl << p4 << endl;

    ptime p5(not_a_date_time);
    assert(p5.is_not_a_date_time());
    ptime p6(pos_infin);
    assert(p6.is_special() && p6.is_pos_infinity());

    ptime p7(date(2010,3,20), hours(12)+minutes(30));

    date d = p7.date();
    time_duration td = p7.time_of_day();
    assert(d.month() == 3 && d.day() == 20);
    assert(td.total_seconds() == 12*3600 + 30*60);

    ptime p8 = p7 + hours(3);
    assert(p7 < p8);
    assert(p8 - p7 == hours(3));
    p8 += months(1);
    assert(p8.date().month() == 4);

    cout << to_simple_string(p7) << endl;
    cout << to_iso_string(p7) << endl;
    cout << to_iso_extended_string(p7) << endl;
/*
output:
============== ptime: =============
2014-Dec-05 11:25:10
2014-Dec-05 03:25:10.716584
2010-Mar-20 12:30:00
20100320T123000
2010-03-20T12:30:00
*/
}

int main()
{
    boost_time_duration();

    boost_ptime();

    return 0;
}
