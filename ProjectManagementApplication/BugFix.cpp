#include "BugFix.h"



BugFix::BugFix()
{
}


BugFix::~BugFix()
{
}

const std::string BugFix::GetDetails()
{
	std::stringstream temp;
	temp << "   >Started: " << start_.getFormatted() << " Ended: " << end_.getFormatted() << " Description: " << desc_ << " ID: " << id_;
	return temp.str();
}
