#include "Project.h"


Project::Project(std::string name, std::string desc, std::string start, std::string deadline)
	: name_(name), desc_(desc), start_(start), deadline_(deadline)
{
}

std::ostream &operator<<(std::ostream &output, Project p)
{
	output << " >Project Name: " << p.GetName() << "\n";
	output << " >" << p.GetTimeSpentFormatted() << "\n";
	output << " >Tasks Involved:\n";
	for (Task t : p.GetTasks())
	{
		output << t;
	}

	return output;
}

std::string Project::GetTimeSpentFormatted()
{
	int minutesSpent = 0;

	for (Task t : Tasks)
	{
		minutesSpent += t.GetMinutesSpent();
	}


	int minute, hour, day, month, year;

	year = minutesSpent / 518400;
	minutesSpent = minutesSpent % 518400;
	month = minutesSpent / 43200;
	minutesSpent = minutesSpent % 43200;
	day = minutesSpent / 1440;
	minutesSpent = minutesSpent % 1440;
	hour = minutesSpent / 60;
	minutesSpent = minutesSpent % 60;
	minute = minutesSpent;

	std::stringstream temp;
	temp << "Time Worked On Project: Years: " << year << " Months: " << month << " Days: " << day << " Hours: " << hour << " Minutes: " << minute;
	return temp.str();
}