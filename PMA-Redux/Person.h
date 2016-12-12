#pragma once
#include <string>
class Person
{
public:
	Person();
	~Person();

	void SetName(std::string s) { name_ = s; }
	std::string & GetName() { return name_; }
	void SetID(int i) { id_ = i; }
	int GetID() { return id_; }
private:
	std::string name_;
	int id_;
};

