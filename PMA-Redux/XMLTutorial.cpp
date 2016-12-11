#include "XMLTutorial.h"

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

XMLTutorial::XMLTutorial()
{
}


XMLTutorial::~XMLTutorial()
{
}

void XMLTutorial::RunCreate()
{
	//create doc
	tinyxml2::XMLDocument doc;
	
	
	//create pointer to route and add route to doc
	tinyxml2::XMLNode * pRoot = doc.NewElement("Root");
	doc.InsertFirstChild(pRoot);
	
	//adding first real element to doc
	//int version
	tinyxml2::XMLElement * pElement = doc.NewElement("IntValue");
	pElement->SetText(10);
	pRoot->InsertEndChild(pElement);
	
	//float version
	pElement = doc.NewElement("FloatValue");
	pElement->SetText(0.5f);
	pRoot->InsertEndChild(pElement);
	
	//using set attribute
	pElement = doc.NewElement("Date");
	pElement->SetAttribute("day", 26);
	pElement->SetAttribute("month", "April");
	pElement->SetAttribute("year", 2014);
	pElement->SetAttribute("dateFormat", "26/04/2014");
	
	pRoot->InsertEndChild(pElement);
	
	//adding items from a list of unknown quantity
	pElement = doc.NewElement("List");
	
	std::vector<int> vecList = { 4, 5, 6, 7, 8, 3, 4, 5, 12 };
	
	for (const auto & item : vecList)
	{
		tinyxml2::XMLElement * pListElement = doc.NewElement("Item");
		pListElement->SetText(item);
	
		pElement->InsertEndChild(pListElement);
	}
	
	pRoot->InsertEndChild(pElement);
	
	//save the file and check for errors
	tinyxml2::XMLError eResult = doc.SaveFile("SavedData.xml");
	//XMLCheckResult(eResult);
}

void XMLTutorial::RunLoad()
{
	//load doc and check for error
	tinyxml2::XMLDocument xmlDoc;
	tinyxml2::XMLError eResult = xmlDoc.LoadFile("SavedData.xml");
	//XMLCheckResult(eResult);


	//store route node in pointer
	tinyxml2::XMLNode * pRoot = xmlDoc.FirstChild();
	//if (pRoot == nullptr) return tinyxml2::XML_ERROR_FILE_READ_ERROR;

	//find element called intvalue
	tinyxml2::XMLElement * pElement = pRoot->FirstChildElement("IntValue");
	//if (pElement == nullptr) return tinyxml2::XML_ERROR_PARSING_ELEMENT;

	//access date from element, assuming its int
	int iOutInt;
	eResult = pElement->QueryIntText(&iOutInt);
	//XMLCheckResult(eResult);

	//do the same process again for float
	pElement = pRoot->FirstChildElement("FloatValue");
	//if (pElement == nullptr) return tinyxml2::XML_ERROR_PARSING_ELEMENT;

	float fOutFloat;
	eResult = pElement->QueryFloatText(&fOutFloat);
	//XMLCheckResult(eResult);

	//now to extract date
	pElement = pRoot->FirstChildElement("Date");
	//if (pElement == nullptr) return tinyxml2::XML_ERROR_PARSING_ELEMENT;

	int iOutDay, iOutYear;

	eResult = pElement->QueryIntAttribute("day", &iOutDay);
	//XMLCheckResult(eResult);

	eResult = pElement->QueryIntAttribute("year", &iOutYear);
	//XMLCheckResult(eResult);


	//to get atribute text, do this
	const char * szAttributeText = nullptr;

	szAttributeText = pElement->Attribute("month");
	//if (szAttributeText == nullptr) return tinyxml2::XML_ERROR_PARSING_ATTRIBUTE;
	std::string strOutMonth = szAttributeText;

	szAttributeText = pElement->Attribute("dateFormat");
	//if (szAttributeText == nullptr) return tinyxml2::XML_ERROR_PARSING_ATTRIBUTE;
	std::string strOutFormat = szAttributeText;

	//now finally extract list
	pElement = pRoot->FirstChildElement("List");
	//if (pElement == nullptr) return tinyxml2::XML_ERROR_PARSING_ELEMENT;

	//create a pointer to iterate through list of "item"s
	tinyxml2::XMLElement * pListElement = pElement->FirstChildElement("Item");
	std::vector<int> vecList;

	while (pListElement != nullptr)
	{
		int iOutListValue;
		eResult = pListElement->QueryIntText(&iOutListValue);
		//XMLCheckResult(eResult);

		vecList.push_back(iOutListValue);
		pListElement = pListElement->NextSiblingElement("Item");
	}
}
