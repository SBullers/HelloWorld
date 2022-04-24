//
// Created by Sara Bullers on 4/9/22.
//

#ifndef ASSIGNMENT2_TIMESPAN_H
#define ASSIGNMENT2_TIMESPAN_H

#include <iostream>
using namespace std;


class TimeSpan {
    // friend class that prints "0:00:00" format
    friend ostream &operator <<(ostream &out, TimeSpan &ts);

public:
    //  constructor that accepts 3 double parameters - hour, minute and second
    explicit TimeSpan(double uHours = 0, double uMinutes = 0, double uSeconds = 0);

    // Addition operator
    // returns total time by calling simplify for valid representation
    TimeSpan operator+ (const TimeSpan &ts);

    // subtraction operator
    //returns total time by calling simplify for valid representation
    TimeSpan operator- (const TimeSpan &ts);

    // Adds given value into itself
    // The total will then be represented correctly by calling simplify()
    void operator+= (const TimeSpan &ts);

    // Subtracts given value into itself
    // The total will then be represented correctly by calling simplify()
    void operator-= (const TimeSpan &ts);

    // multiplication operator
    // The total will then be represented correctly by calling simplify()
    TimeSpan operator* (unsigned int number);

    //checks if values are equal
    // returns true if values are the same
    bool operator== (TimeSpan const &ts);

    // checks if values are not equal
    // returns true if values are not the same
    bool  operator!= (const TimeSpan &ts);

    // greater operator
    //  returns true if user values are greater than TimeSpan values
    bool operator> (const TimeSpan &ts) const;

    // greater than operator
    // returns true if user values are equal or greater than TimeSpan values
    bool operator>= (const TimeSpan &ts) const;

    // less than operator
    //  returns true if user values are lesser than TimeSpan values
    bool operator< (const TimeSpan &ts) const;

    // less than or equal operator
    //  returns true if user values are lesser than or equal TimeSpan values
    bool operator<= (const TimeSpan &ts) const;

    // getter for hour component
    int getHour();

    // getter for minute component
    int getMinute();

    // getter for second component
    int getSecond();


private:
    // creates a valid representation of TimeSpan, to ensure reduction into hours, minutes and seconds.
   void simplify();
    // reduces all hours and minutes to seconds, adds all seconds and returns those totalSeconds
   int toSeconds() const;
   double hours;
   int fHours;
   double minutes;
   int fMinutes;
   double seconds;
   int fSeconds;
};

#endif //ASSIGNMENT2_TIMESPAN_H
