#include "WorkDone.h"



WorkDone::WorkDone()
{
}


WorkDone::~WorkDone()
{
}

const std::string WorkDone::GetDetails()
{
	std::stringstream temp;
	temp << "Start: " << start_.getFormatted() << " Ended: " << end_.getFormatted() << " Description: " << desc_;
	return temp.str();
}
