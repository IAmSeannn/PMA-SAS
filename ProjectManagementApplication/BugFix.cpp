#include "BugFix.h"



BugFix::BugFix()
{
}


BugFix::~BugFix()
{
}

const std::string BugFix::GetDetails() const
{
	std::stringstream temp;
	temp << spacer << "Bug Fix: " << start_.getFormatted() << " - " << end_.getFormatted() << " Description: " << desc_ << " ID: " << id_;
	return temp.str();
}

void BugFix::GetInformationForNewClass()
{

}

