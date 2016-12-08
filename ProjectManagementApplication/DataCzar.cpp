#include "DataCzar.h"

DataCzar::DataCzar()
{
}

tinyxml2::XMLError DataCzar::SetUp(const std::string & path)
{
	return LoadInXML(path);
}

DataCzar * DataCzar::Current;

tinyxml2::XMLError DataCzar::LoadInXML(const std::string path)
{
	//load in file and get pointer to root
	tinyxml2::XMLDocument xmlDoc;
	tinyxml2::XMLError success;
	success = xmlDoc.LoadFile(path.c_str());
	if (success == tinyxml2::XML_SUCCESS)
	{
		tinyxml2::XMLNode * pRoot = xmlDoc.FirstChild();

		//load projects using root
		LoadInProjects(pRoot);
	}
	return success;
}

void DataCzar::LoadInProjects(tinyxml2::XMLNode * pRoot)
{
	//loop through all projects
	tinyxml2::XMLElement * pProjectHeader = pRoot->FirstChildElement("project");
	while (pProjectHeader != nullptr)
	{
		Project p;

		//get element of name
		tinyxml2::XMLElement * pProjectElement = pProjectHeader->FirstChildElement("name");
		p.SetName(pProjectElement->GetText());
		//do same again for desc
		pProjectElement = pProjectHeader->FirstChildElement("desc");
		p.SetDesc(pProjectElement->GetText());
		//for start datetime
		pProjectElement = pProjectHeader->FirstChildElement("start");
		p.SetStart(pProjectElement->GetText());
		//for end datetime
		pProjectElement = pProjectHeader->FirstChildElement("end");
		p.SetDeadline(pProjectElement->GetText());

		//loop through tasks and add
		p.SetTasks(LoadInTasks(pProjectHeader));

		//add project to list of projects
		Projects.push_back(p);
		//move xml pointer to next project in file
		pProjectHeader = pProjectHeader->NextSiblingElement("project");
	}
}

std::vector<Task> DataCzar::LoadInTasks(tinyxml2::XMLNode * pCurrentProject)
{
	//temp vector to store tasks as added
	std::vector<Task> temp;
	//loop through all tasks
	tinyxml2::XMLElement * pTaskHeader = pCurrentProject->FirstChildElement("task");
	while (pTaskHeader != nullptr)
	{
		Task t;

		//get element of name
		tinyxml2::XMLElement * pTaskElement = pTaskHeader->FirstChildElement("name");
		t.SetName(pTaskElement->GetText());
		//do same again for desc
		pTaskElement = pTaskHeader->FirstChildElement("desc");
		t.SetDesc(pTaskElement->GetText());
		//do same for start
		pTaskElement = pTaskHeader->FirstChildElement("start");
		t.SetStart(pTaskElement->GetText());
		//do same for end
		pTaskElement = pTaskHeader->FirstChildElement("end");
		t.SetDeadline(pTaskElement->GetText());

		//do some stuff for time allocations
		//might break. complicated. help
		//get time allocation element
		pTaskElement = pTaskHeader->FirstChildElement("timeAllocations");
			t.SetTAs(LoadInTAs(pTaskElement));
		//add t to temp vector
		temp.push_back(t);

		//move xml pointer to next project in file
		pTaskHeader = pTaskHeader->NextSiblingElement("task");
	}
	return temp;
}

std::vector<TimeAllocation*> DataCzar::LoadInTAs(tinyxml2::XMLNode * pTARoot)
{
	//temp vector to store TAs as added
	std::vector<TimeAllocation*> temp;
	//loop through all TAs, 3 times, once for each type
	//first MEETING
	tinyxml2::XMLElement * pTAHeader = pTARoot->FirstChildElement("meeting");
	while (pTAHeader != nullptr)
	{
		Meeting *m = new Meeting();

		//get element of attendees
		tinyxml2::XMLElement * pMeetingElement = pTAHeader->FirstChildElement("attendees");
		m->SetAttendees(pMeetingElement->GetText());
		//do for start and end
		pMeetingElement = pTAHeader->FirstChildElement("start");
		m->SetStart(pMeetingElement->GetText());
		pMeetingElement = pTAHeader->FirstChildElement("end");
		m->SetEnd(pMeetingElement->GetText());

		//add m to temp vector
		temp.push_back(m);

		//move xml pointer to next project in file
		pTAHeader = pTAHeader->NextSiblingElement("meeting");
	}
	//second WORKDONE
	pTAHeader = pTARoot->FirstChildElement("workDone");
	while (pTAHeader != nullptr)
	{
		WorkDone *w = new WorkDone();

		//get element of desc
		tinyxml2::XMLElement * pWorkDoneElement = pTAHeader->FirstChildElement("desc");
		w->SetDesc(pWorkDoneElement->GetText());
		//start and end
		pWorkDoneElement = pTAHeader->FirstChildElement("start");
		w->SetStart(pWorkDoneElement->GetText());
		pWorkDoneElement = pTAHeader->FirstChildElement("end");
		w->SetEnd(pWorkDoneElement->GetText());

		//add m to temp vector
		temp.push_back(w);

		//move xml pointer to next project in file
		pTAHeader = pTAHeader->NextSiblingElement("workDone");
	}
	//third BUGFIX
	pTAHeader = pTARoot->FirstChildElement("bugFix");
	while (pTAHeader != nullptr)
	{
		BugFix *b = new BugFix();

		//get element of desc
		tinyxml2::XMLElement * pBugFixElement = pTAHeader->FirstChildElement("desc");
		b->SetDesc(pBugFixElement->GetText());
		//start and end
		pBugFixElement = pTAHeader->FirstChildElement("start");
		b->SetStart(pBugFixElement->GetText());
		pBugFixElement = pTAHeader->FirstChildElement("end");
		b->SetEnd(pBugFixElement->GetText());
		//get element of id to int
		pBugFixElement = pTAHeader->FirstChildElement("id");
		int i;
		pBugFixElement->QueryIntText(&i);
		b->SetID(i);

		//add b to temp vector
		temp.push_back(b);

		//move xml pointer to next project in file
		pTAHeader = pTAHeader->NextSiblingElement("bugFix");
	}
	//fourth RESEARCH
	pTAHeader = pTARoot->FirstChildElement("research");
	while (pTAHeader != nullptr)
	{
		 Research *r = new Research();

		//get element of desc
		tinyxml2::XMLElement * pBugFixElement = pTAHeader->FirstChildElement("details");
		r->SetDetails(pBugFixElement->GetText());
		//start and end
		pBugFixElement = pTAHeader->FirstChildElement("start");
		r->SetStart(pBugFixElement->GetText());
		pBugFixElement = pTAHeader->FirstChildElement("end");
		r->SetEnd(pBugFixElement->GetText());
		//get element of id to int

		//add b to temp vector
		temp.push_back(r);

		//move xml pointer to next project in file
		pTAHeader = pTAHeader->NextSiblingElement("research");
	}

	return temp;
}

DataCzar::~DataCzar()
{
}


