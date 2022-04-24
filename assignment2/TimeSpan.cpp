//
// Created by Sara Bullers on 4/9/22.
//

#include <cmath>
#include <iomanip>
#include "TimeSpan.h"

ostream &operator<<(ostream &out, TimeSpan &ts)
{
    ts.simplify();
    out << ts.fHours << ":" << setw(2) << setfill('0') << ts.fMinutes << ":" << setw(2) << setfill('0')
    << ts.fSeconds;
    return out;
}

// constructor
TimeSpan::TimeSpan(double uHours, double uMinutes, double uSeconds)
{
    seconds = uSeconds;
    minutes = uMinutes;
    hours = uHours;

    fSeconds = 0;
    fMinutes = 0;
    fHours = 0;
}

// getter for hour
int TimeSpan::getHour()
{
    simplify();
    return fHours;
}

// getter for Minutes
int TimeSpan::getMinute() {
    simplify();
    return fMinutes;
}

// getter for seconds
int TimeSpan::getSecond() {
    simplify();
    return fSeconds;
}

TimeSpan TimeSpan::operator+(const TimeSpan &ts)
{
    int addedSeconds = toSeconds() + ts.toSeconds();
    TimeSpan newTimeSpan = TimeSpan (0,0, addedSeconds);
    newTimeSpan.simplify();
    return newTimeSpan;
}

TimeSpan TimeSpan::operator-(const TimeSpan &ts)
{
    int subtractedSeconds = toSeconds() - ts.toSeconds();
    TimeSpan newTimeSpan = TimeSpan(0,0, subtractedSeconds);
    newTimeSpan.simplify();
    return newTimeSpan;
}

void TimeSpan::operator+=(const TimeSpan &ts)
{
    seconds = toSeconds() + ts.toSeconds();
    hours = 0;
    minutes = 0;
    simplify();
}

void TimeSpan::operator-=(const TimeSpan &ts)
{
    seconds = toSeconds() - ts.toSeconds();
    hours = 0;
    minutes =0;
    simplify();
}

TimeSpan TimeSpan::operator*(unsigned int number)
{
    int multipliedSeconds = number * toSeconds();
    TimeSpan newTimeSpan = TimeSpan (0,0, multipliedSeconds);
    newTimeSpan.simplify();
    return newTimeSpan;
}

bool TimeSpan::operator==(TimeSpan const &ts)  {

    return toSeconds() == ts.toSeconds();
}

bool TimeSpan::operator!=( TimeSpan const &ts)  {
    return toSeconds() != ts.toSeconds();
}

bool TimeSpan::operator>(const TimeSpan &ts) const {
    return toSeconds() > ts.toSeconds();
}
bool TimeSpan::operator<(const TimeSpan &ts) const {
    return toSeconds() < ts.toSeconds();
}

bool TimeSpan::operator>=(const TimeSpan &ts) const {
    return toSeconds() >= ts.toSeconds();
}

bool TimeSpan::operator<=(const TimeSpan &ts) const {
    return toSeconds() <= ts.toSeconds();
}

void TimeSpan::simplify()
{
    int totalSeconds = toSeconds();
    if (totalSeconds >= 0) {
        // get hours
        int tempHours = totalSeconds / (3600);
        // makes hour a single integer number
        fHours = floor(tempHours);
        //get minutes
        int secondsLeft = totalSeconds - (tempHours * 3600);
        int tempMinutes = secondsLeft / 60;
        fMinutes = floor(tempMinutes);
        // gets leftover seconds
        fSeconds = round(secondsLeft - (tempMinutes * 60));
    } else
    {
        fHours = 0;
        fMinutes = 0;
        fSeconds = 0;
    }
}

int TimeSpan::toSeconds() const
{
    // reduce everything to seconds
    int totalSeconds = hours * 3600 + minutes * 60 + seconds;
    return totalSeconds;
};