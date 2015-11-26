#include "Topic.h"



Topic::Topic()
{
}

Topic::Topic(string aName):
	name(aName)
{
}

string Topic::getName()
{
	return name;
}


Topic::~Topic()
{
}
