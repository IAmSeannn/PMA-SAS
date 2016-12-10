#include "DataCzar.h"

DataCzar * DataCzar::Current;

DataCzar::DataCzar()
{
}

tinyxml2::XMLError DataCzar::SetUp(const std::string & path)
{
	//clean all existing data
	Projects.clear();
	return LoadInXML(path);
}

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
		DataCzar::Current->path = path;
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

std::vector<std::shared_ptr<TimeAllocation>> DataCzar::LoadInTAs(tinyxml2::XMLNode * pTARoot)
{
	//temp vector to store TAs as added
	std::vector<std::shared_ptr<TimeAllocation>> temp;
	//loop through all TAs, 3 times, once for each type
	//first MEETING
	tinyxml2::XMLElement * pTAHeader = pTARoot->FirstChildElement("meeting");
	while (pTAHeader != nullptr)
	{
		std::shared_ptr<Meeting> m(new Meeting);

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
		std::shared_ptr<WorkDone> w(new WorkDone);

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
		std::shared_ptr<BugFix> b(new BugFix);

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
		 std::shared_ptr<Research> r(new Research);

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

//clear the file and then save new copy

void DataCzar::SaveToFile()
{
	tinyxml2::XMLDocument doc;

	//create pointer to route and add route to doc
	tinyxml2::XMLNode * pRoot = doc.NewElement("root");
	doc.InsertFirstChild(pRoot);

	//element
	tinyxml2::XMLElement * pProject;
	tinyxml2::XMLElement * pTask;
	tinyxml2::XMLElement * pTimeAllocation;
	tinyxml2::XMLElement * pTimeAllocationSub;

	tinyxml2::XMLElement * pElement;

	for (Project p : Current->Projects)
	{
		//create project tag
		pElement = doc.NewElement("project");
		//add it to root
		pRoot->InsertEndChild(pElement);
		//set project as parent and add contents
		pProject = pElement;

		//NAME
		//create name tag
		pElement = doc.NewElement("name");
		//populate it
		pElement->SetText(p.GetName().c_str());
		//add it to doc
		pProject->InsertEndChild(pElement);

		//DESC
		//create desc tag
		pElement = doc.NewElement("desc");
		//populate it
		pElement->SetText(p.GetDesc().c_str());
		//add it to doc
		pProject->InsertEndChild(pElement);

		//START
		//create start tag
		pElement = doc.NewElement("start");
		//populate it
		pElement->SetText(p.GetStart().c_str());
		//add it to doc
		pProject->InsertEndChild(pElement);

		//END
		//create end tag
		pElement = doc.NewElement("end");
		//populate it
		pElement->SetText(p.GetDeadline().c_str());
		//add it to doc
		pProject->InsertEndChild(pElement);

		for (auto t : p.GetTasks())
		{
			//SWITCH TO TASK
			//create task tag
			pElement = doc.NewElement("task");
			//add it to project (parent)
			pProject->InsertEndChild(pElement);
			//set task as parent and add contents
			pTask = pElement;

			//NAME
			//create name tag
			pElement = doc.NewElement("name");
			//populate it
			pElement->SetText(t.GetName().c_str());
			//add it to doc
			pTask->InsertEndChild(pElement);

			//DESC
			//create desc tag
			pElement = doc.NewElement("desc");
			//populate it
			pElement->SetText(t.GetDesc().c_str());
			//add it to doc
			pTask->InsertEndChild(pElement);

			//START
			//create start tag
			pElement = doc.NewElement("start");
			//populate it
			pElement->SetText(t.GetStart().c_str());
			//add it to doc
			pTask->InsertEndChild(pElement);

			//END
			//create end tag
			pElement = doc.NewElement("end");
			//populate it
			pElement->SetText(t.GetDeadline().c_str());
			//add it to doc
			pTask->InsertEndChild(pElement);

			//SWITCH TO TIME ALLOCATIONS
			//create timealocation tag
			pElement = doc.NewElement("timeAllocations");
			//add it to project (parent)
			pTask->InsertEndChild(pElement);
			//set timeAllocations as parent and add contents
			pTimeAllocation = pElement;

			//NOW GO INTO LOOP, FUNNY FORMAT OF TIMEALLOC REQUIRES THIS
			for (auto ta : t.GetTAs())
			{
				//SWITCH TO TIME ALLOCATIONS PART 2
				//have to find out what kind to make first
				//gulp

				if (std::dynamic_pointer_cast<Meeting>(ta))
				{
					//create meeting tag
					pElement = doc.NewElement("meeting");
					//add it to project (parent)
					pTimeAllocation->InsertEndChild(pElement);
					//set timeAllocations as parent and add contents
					pTimeAllocationSub = pElement;

					//START
					//create start tag
					pElement = doc.NewElement("start");
					//populate it
					pElement->SetText(ta->GetStart().c_str());
					//add it to doc
					pTimeAllocationSub->InsertEndChild(pElement);

					//END
					//create end tag
					pElement = doc.NewElement("end");
					//populate it
					pElement->SetText(ta->GetEnd().c_str());
					//add it to doc
					pTimeAllocationSub->InsertEndChild(pElement);

					//ATTENDEES
					//create end tag
					pElement = doc.NewElement("attendees");
					//populate it
					pElement->SetText(std::dynamic_pointer_cast<Meeting>(ta)->GetAttendees().c_str());
					//add it to doc
					pTimeAllocationSub->InsertEndChild(pElement);

				}
				else if (std::dynamic_pointer_cast<WorkDone>(ta))
				{
					//create workDone tag
					pElement = doc.NewElement("workDone");
					//add it to project (parent)
					pTimeAllocation->InsertEndChild(pElement);
					//set timeAllocations as parent and add contents
					pTimeAllocationSub = pElement;

					//START
					//create start tag
					pElement = doc.NewElement("start");
					//populate it
					pElement->SetText(ta->GetStart().c_str());
					//add it to doc
					pTimeAllocationSub->InsertEndChild(pElement);

					//END
					//create end tag
					pElement = doc.NewElement("end");
					//populate it
					pElement->SetText(ta->GetEnd().c_str());
					//add it to doc
					pTimeAllocationSub->InsertEndChild(pElement);

					//DESC
					//create end tag
					pElement = doc.NewElement("desc");
					//populate it
					pElement->SetText(std::dynamic_pointer_cast<WorkDone>(ta)->GetDesc().c_str());
					//add it to doc
					pTimeAllocationSub->InsertEndChild(pElement);
				}
				else if (std::dynamic_pointer_cast<BugFix>(ta))
				{
					//create bugfix tag
					pElement = doc.NewElement("bugFix");
					//add it to project (parent)
					pTimeAllocation->InsertEndChild(pElement);
					//set timeAllocations as parent and add contents
					pTimeAllocationSub = pElement;

					//START
					//create start tag
					pElement = doc.NewElement("start");
					//populate it
					pElement->SetText(ta->GetStart().c_str());
					//add it to doc
					pTimeAllocationSub->InsertEndChild(pElement);

					//END
					//create end tag
					pElement = doc.NewElement("end");
					//populate it
					pElement->SetText(ta->GetEnd().c_str());
					//add it to doc
					pTimeAllocationSub->InsertEndChild(pElement);

					//DESC
					//create end tag
					pElement = doc.NewElement("desc");
					//populate it
					pElement->SetText(std::dynamic_pointer_cast<BugFix>(ta)->GetDesc().c_str());
					//add it to doc
					pTimeAllocationSub->InsertEndChild(pElement);

					//ID
					//create end tag
					pElement = doc.NewElement("id");
					//populate it
					pElement->SetText(std::dynamic_pointer_cast<BugFix>(ta)->GetID());
					//add it to doc
					pTimeAllocationSub->InsertEndChild(pElement);
				}
				else if (std::dynamic_pointer_cast<Research>(ta))
				{
					//create research tag
					pElement = doc.NewElement("research");
					//add it to project (parent)
					pTimeAllocation->InsertEndChild(pElement);
					//set timeAllocations as parent and add contents
					pTimeAllocationSub = pElement;

					//START
					//create start tag
					pElement = doc.NewElement("start");
					//populate it
					pElement->SetText(ta->GetStart().c_str());
					//add it to doc
					pTimeAllocationSub->InsertEndChild(pElement);

					//END
					//create end tag
					pElement = doc.NewElement("end");
					//populate it
					pElement->SetText(ta->GetEnd().c_str());
					//add it to doc
					pTimeAllocationSub->InsertEndChild(pElement);

					//DESC
					//create end tag
					pElement = doc.NewElement("details");
					//populate it
					pElement->SetText(std::dynamic_pointer_cast<Research>(ta)->GetDetails().c_str());
					//add it to doc
					pTimeAllocationSub->InsertEndChild(pElement);
				}
			}
		}
	}

	//save it all here
	doc.SaveFile(Current->path.c_str());
	
}