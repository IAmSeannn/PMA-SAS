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