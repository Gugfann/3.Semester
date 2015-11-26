#pragma once
#include "Publication.h"
class MyBooks
{
public:
	MyBooks();
	MyBooks(string aCollectionName);
	void addPublication(Publication &aPubl);
	void findNonFictionWithMoreThanOneAuthor();
	void findPubsWithNonFictionTopic(string aTopic);
	void print();
	virtual ~MyBooks();
protected:
	vector<Publication*> publications;
	string collectionName;
};

