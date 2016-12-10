#pragma once
#include <string>
#include <sstream>
#include <iomanip>


class DateTime
{
public:
	DateTime() {};
	~DateTime() {};
	DateTime(std::string);             // parse from a string format
	std::string getFormatted() const;  // return as a formatted string
	const int GetDifferent(const DateTime other) const; //other should always be later, ie use a start.getDifferent(other) where other is the end.
	const int GetTimeInMinutes() const; // returns time in minutes

private:
	int minute; // 0 to 59
	int hour;   // 0 to 23
	int day;    // 1 to 31
	int month;  // 1 to 12
	int year; //in all caluclations, 2000 is taken from it, and added back where required. This helps keep the numbers manageable.
};

