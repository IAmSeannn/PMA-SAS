#include "BugFix.h"



BugFix::BugFix()
{
}


BugFix::~BugFix()
{
}

std::string BugFix::GetDetails()
{
	std::stringstream temp;
	temp << start_.getFormatted() << " " << end_.getFormatted() << " " << desc_ << " " << id_;
	return temp.str();
}
