#include "DateTime.h"

DateTime::DateTime(std::string datetime)
{
	// DD/MM/YYYY HH:MM
	std::istringstream iss(datetime);
	char dump;
	iss >> day >> dump >> month >> dump >> year >> hour >> dump >> minute;
}


std::string DateTime::getFormatted() const
{
	// DD/MM/YYYY HH:MM
	std::ostringstream oss;
	oss << std::setfill('0');
	oss << std::setw(2) << day << '/';
	oss << std::setw(2) << month << '/';
	oss << year << ' ';
	oss << std::setw(2) << hour << ':';
	oss << std::setw(2) << minute;
	return oss.str();
}

const int DateTime::GetDifferent(const DateTime end) const
{
	int yearDif, monthDif, dayDif, hourDif, minuteDif;

	//work out years
	yearDif = end.year - year;
	monthDif = end.month - month;
	dayDif = end.day - day;
	hourDif = end.hour - hour;
	minuteDif = end.minute - minute;

	return ((((((((yearDif) * 12) + monthDif) * 30) + dayDif) * 25) + hourDif) * 60) + minuteDif;
}

const int DateTime::GetTimeInMinutes() const
{
	return minute + (hour * 60) + (day * 1440) + (month * 43200) + ((year-1970) * 518400);
}