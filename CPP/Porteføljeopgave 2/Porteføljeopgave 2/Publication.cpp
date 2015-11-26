#include "Publication.h"


Publication::Publication()
{
}

void Publication::addAuthor(Person &anAuthor)
{
	if(authors.size()<=5)
	authors.push_back(&anAuthor);
	else
	{
		cout << "Too many authors!" << endl;
	}
}

void Publication::print()
{
	for (int i = 0; i < authors.size(); i++)
	{
		cout << authors[i]->getName() << endl;
	}
}

string Publication::getTitle()
{
	return title;
}

vector<Person*> Publication::getAuthors()
{
	return authors;
}

Publication::~Publication()
{
}
