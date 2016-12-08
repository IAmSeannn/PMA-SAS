#include "WorkDone.h"



WorkDone::WorkDone()
{
}


WorkDone::~WorkDone()
{
}

const std::string WorkDone::GetDetails() const
{
	std::stringstream temp;
	temp << spacer << "Work Done: " << start_.getFormatted() << " - " << end_.getFormatted() << " Description: " << desc_;
	return temp.str();
}
