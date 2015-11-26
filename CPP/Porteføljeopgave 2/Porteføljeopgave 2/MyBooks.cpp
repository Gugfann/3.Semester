#include "MyBooks.h"
#include "NonFiction.h"

MyBooks::MyBooks()
{
}

MyBooks::MyBooks(string aCollectionName):
	collectionName(aCollectionName)
{
}

void MyBooks::addPublication(Publication &aPubl)
{
	publications.push_back(&aPubl);
}

void MyBooks::findNonFictionWithMoreThanOneAuthor()
{
	for (int i = 0; i < publications.size(); i++)
	{
		NonFiction* n = dynamic_cast<NonFiction*>(publications[i]);
		if (n != 0) {
			if(publications[i]->getAuthors().size() > 1)
			cout << "Non-fiction publication with more than one author: " << endl << publications[i]->getTitle() << endl << endl;
		}
	}		
}

void MyBooks::findPubsWithNonFictionTopic(string aTopic)
{
	for (int i = 0; i < publications.size(); i++)
	{
		NonFiction* n = dynamic_cast<NonFiction*>(publications[i]);
		if (n != 0) 
		{
			if (n->getTopic()->getName() == aTopic)
				cout << "Non-fiction publication with " << aTopic << " topic: " << endl << publications[i]->getTitle() << endl << endl;
		}
	}
}

void MyBooks::print()
{

	for (int i = 0; i < publications.size(); i++)
	{
		cout << publications[i]->getTitle() << endl;
	}
}

MyBooks::~MyBooks()
{
}
