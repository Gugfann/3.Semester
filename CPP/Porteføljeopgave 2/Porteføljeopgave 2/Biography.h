#pragma once
#include "Publication.h"
class Biography :
	public Publication
{
public:
	Biography();
	Biography(string aTitle, int aYear);
	virtual ~Biography();
};

