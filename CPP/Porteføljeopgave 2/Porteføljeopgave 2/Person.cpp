#include "Person.h"



Person::Person()
{
}

Person::Person(string aName, string aNation, int aBYear, int aDYear):
	name(aName), nationality(aNation), yearOfBirth(aBYear), yearOfDeath(aDYear)
{
}

string Person::getName()
{
	return name;
}


Person::~Person()
{
}
