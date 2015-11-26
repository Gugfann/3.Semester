#pragma once
#include "Person.h"
#include <vector>
#include <iostream>

class Publication
{
public:
	Publication();
	void addAuthor(Person &anAuthor);
	void print();
	string getTitle();
	vector<Person*> getAuthors();
	virtual ~Publication();
protected:
	string title;
	int year;
	vector<Person*> authors;
};

