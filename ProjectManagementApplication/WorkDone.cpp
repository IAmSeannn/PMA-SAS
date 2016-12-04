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
	temp << " " << desc_;
	//temp << start_.getFormatted() << " " << end_.getFormatted() << " " << desc_;
	return temp.str();
}
