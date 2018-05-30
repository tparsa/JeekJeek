#include "timeAndDate.hpp"

Date::Date()
{
	time_t nowTime = time(NULL);
	struct tm * timeInfo = localtime(&nowTime);

	year = timeInfo->tm_year + 1900;
	month = timeInfo->tm_mon + 1;
	day = timeInfo->tm_mday;
}

bool Date::operator< (const Date& secondDate) const
{
	if(year < secondDate.year)
		return true;
	else if(year > secondDate.year)
		return false;
	if(month < secondDate.month)
		return true;
	else if(month > secondDate.month)
		return false;
	if(day < secondDate.day)
		return true;
	return false;
}

Time::Time()
{
	time_t nowTime = time(NULL);
	struct tm * timeInfo = localtime(&nowTime);

	hour = timeInfo->tm_hour;
	minute = timeInfo->tm_min;
}

bool Time::operator< (const Time& secondTime) const
{
	if(hour < secondTime.hour)
		return true;
	else if(hour > secondTime.hour)
		return false;

	if(minute < secondTime.minute)
		return true;

	return false;
}