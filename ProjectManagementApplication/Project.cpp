#include "Project.h"


Project::Project(std::string name, std::string desc, std::string start, std::string deadline)
	: name_(name), desc_(desc), start_(start), deadline_(deadline)
{
}

std::ostream &operator<<(std::ostream &output, Project p)
{
	output << " >Project Name: " << p.GetName() << "\n";
	output << " >Tasks Involved:\n";
	for (Task t : p.GetTasks())
	{
		output << t;
	}

	return output;
}