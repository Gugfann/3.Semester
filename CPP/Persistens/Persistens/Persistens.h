#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Person.h"
using namespace std;

class Persistens
{
public:
	Persistens();
	void writeToFile(string aText);
	void writePersonToFile(Person aPerson);
	string loadFromFile();
	Person loadPersonFromFile();
	~Persistens();
protected:
	ofstream randomFile;
};

