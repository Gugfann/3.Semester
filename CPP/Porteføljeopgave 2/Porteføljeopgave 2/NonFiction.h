#pragma once
#include "Publication.h"
#include "Topic.h"
class NonFiction :
	public Publication
{
public:
	NonFiction();
	NonFiction(string aTitle, int aYear, Topic& aTopic);
	Topic* getTopic();
	virtual ~NonFiction();
protected:
	Topic* topic;
};