#ifndef TIMEANDDATE_HPP
#define TIMEANDDATE_HPP

#include <ctime>
#include <cstdio>

class Date 
{

private:
	int year;
	int month;
	int day;
public:
	Date();
	bool operator< (const Date& secondDate) const;
	void print () { printf("%d/%d/%d", year, month, day); }
};

class Time
{
private:
	int hour;
	int minute;
public:
	Time();
	bool operator< (const Time& secondTime) const;
	void print() { printf("%d:%d\n", hour, minute);}
};

class TimeAndDate
{
	Date date;
	Time time;

public:
	TimeAndDate() {}
	TimeAndDate presentTime() { return TimeAndDate(); }

	bool operator>= (const TimeAndDate& secondTnd) const
	{
		Date sDate = secondTnd.date;
		Time sTime = secondTnd.time;
		if(date < sDate)
			return false;
		if(time < sTime)
			return false;
		return true;
	}

	void print(){ date.print(); printf(" "); time.print(); }
};

#endif