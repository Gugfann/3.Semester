#pragma once
#include "Publication.h"
class Fiction :
	public Publication
{
public:
	Fiction();
	Fiction(string aTitle, int aYear);
	virtual ~Fiction();
};

