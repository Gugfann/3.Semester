#pragma once
#include <string>
using namespace std;

class Person
{
public:
	Person();
	Person(string aName, string aNation, int aBYear, int aDYear);
	string getName();
	string getNationality();
	int getYOB();
	int getYOD();
	virtual ~Person();
protected:
	string name;
	string nationality;
	int yearOfBirth;
	int yearOfDeath;
};

