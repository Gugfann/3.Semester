#pragma once
#include <string>
using namespace std;
class Topic
{
public:
	Topic();
	Topic(string aName);
	string getName();
	virtual ~Topic();
protected:
	string name;	
};

