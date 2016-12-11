#pragma once
#include <string>
class Person
{
public:
	Person();
	~Person();

	void SetName(std::string s) { name_ = s; }
	void SetID(int i) { id_ = i; }
private:
	std::string name_;
	int id_;
};

