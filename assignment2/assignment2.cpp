#include <iostream>
#include <sstream>
#include <cassert>
#include "TimeSpan.h"

using namespace std;

// testing constructor
void test1()
{
    TimeSpan ts (1,20, 30);
    stringstream ss;
    ss << ts;
    assert (ss.str () == "1:20:30");

    TimeSpan ts2 (4, -20, -90);
    ss.str("");
    ss << ts2;
    assert (ss.str() == "3:38:30");

    TimeSpan ts3 (1.5, 30.5, -90);
    ss.str("");
    ss << ts3;
    assert (ss.str() == "1:59:00");

    TimeSpan ts4 (0, 0.07, 0);
    ss.str("");
    ss << ts4;
    assert (ss.str() == "0:00:04");

    TimeSpan ts5 (0, 60, 0);
    ss.str("");
    ss << ts5;
    assert (ss.str() == "1:00:00");

    TimeSpan ts6 (0, 60, 60);
    ss.str("");
    ss << ts6;
    assert (ss.str() == "1:01:00");

    TimeSpan ts7 (0, 59, 60);
    ss.str("");
    ss << ts7;
    assert (ss.str() == "1:00:00");

    TimeSpan ts8 (1, 35, 61);
    assert(ts8.getHour() == 1);
    assert(ts8.getMinute() == 36);
    assert(ts8.getSecond() == 1);

    cout << "test1 is complete" << endl;
}

// testing equality, addition, subtraction and multiplication
void test2 ()
{
    TimeSpan ts (1,20,30);
    TimeSpan ts2 (1,20,30);
    TimeSpan ts3 (0,0,0);
    assert(ts == ts2);
    assert(! (ts != ts2));
    assert(ts != ts3);
    assert(ts > ts3);
    assert(ts3 < ts2);
    assert(ts >= ts3);
    assert(ts >= ts2);
    assert(ts3 <= ts2);
    assert(ts2 <= ts);
    assert((ts + ts + ts) == (ts2 * 3));
    assert((ts * 5) == (ts2 * 4) + ts2);
    assert((ts * 5) == (ts2 * 6) - ts2);
    assert((ts + ts - ts) == ((ts2 * 2) - ts));
    assert((ts - ts2) == ts3);
    assert((ts3 * 5) == ts3);
    cout << "test2 is complete" << endl;
}

// testing in place addition and subtraction
void test3 ()
{
    TimeSpan ts = TimeSpan(1,20,30);
    TimeSpan ts2 (1,20,30);
    TimeSpan ts3 (0,0,0);

    ts += ts2;
    assert(ts == (ts2 * 2));

    ts = TimeSpan(1, 20, 30);
    ts -= ts2;
    assert(ts == ts3);
    cout << "test3 is complete" << endl;
}

// testing various constructor parameters
void test4 ()
{
    TimeSpan ts (1,20);
    stringstream ss;
    ss << ts;
    assert (ss.str () == "1:20:00");

    TimeSpan ts2 (4);
    ss.str("");
    ss << ts2;
    assert (ss.str() == "4:00:00");

    TimeSpan ts3;
    ss.str("");
    ss << ts3;
    assert (ss.str() == "0:00:00");

    TimeSpan ts4 (0,-1, -20);
    ss.str("");
    ss << ts4;
    assert (ss.str() == "0:00:00");

    cout << "test4 is complete" << endl;
}

void TestAll ()
{
    test1();
    test2();
    test3();
    test4();
}

int main()
{
    TestAll();
    cout << "Done." << std::endl;
    return 0;
}
