#include "NonFiction.h"



NonFiction::NonFiction()
{
}

NonFiction::NonFiction(string aTitle, int aYear, Topic &aTopic):
	topic(&aTopic)
{
	title = aTitle;
	year = aYear;
}

Topic* NonFiction::getTopic()
{
	return topic;
}


NonFiction::~NonFiction()
{
}
