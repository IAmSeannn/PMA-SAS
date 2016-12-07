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
	temp << spacer << "Work Done: " << start_.getFormatted() << " - " << end_.getFormatted() << " Description: " << desc_;
	return temp.str();
}
