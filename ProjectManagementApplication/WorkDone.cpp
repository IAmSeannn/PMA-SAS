#include "WorkDone.h"



WorkDone::WorkDone()
{
}


WorkDone::~WorkDone()
{
}

std::string WorkDone::GetDetails()
{
	std::stringstream temp;
	temp << start_.getFormatted() << " " << end_.getFormatted() << " " << desc_;
	return temp.str();
}
