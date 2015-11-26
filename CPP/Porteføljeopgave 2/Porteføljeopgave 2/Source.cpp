#include "Publication.h"
#include "MyBooks.h"
#include "Fiction.h"
#include "NonFiction.h"
#include "Biography.h"

int main()
{
	Topic history("History");
	Topic programming("Programming");
	Topic software("Software Engineering");

	Person larman("Craig Larman", "American", 1958, 0);
	Person stoustrup("Bjarne Stroustrup", "Danish", 1950, 0);
	Person mah("Martin A. Hansen", "Danish", 1909, 1955);
	Person hs("Hans Scherfig", "Danish", 1905, 1978);
	Person straede("Therkel Stræde", "Danish", 1958, 0);
	Person larsen("Dennis Larsen", "Danish", 1966, 0);
	Person korda("Michael Korda", "American", 1933, 0);
	Person mcc("David McCollough", "American", 1933, 0);
	Person dallek("Robert Dallek", "American", 1934, 0);

	Fiction dff("Den forsvundne Fuldmægtig", 1937);
	dff.addAuthor(hs);

	Fiction l("Løgneren", 1950);
	l.addAuthor(mah);

	NonFiction uml("Applying UML & Patterns", 2006, software);
	uml.addAuthor(larman);

	NonFiction cpp("The C++ programming language", 2013, programming);
	cpp.addAuthor(stoustrup);

	NonFiction siv("En skole i vold", 2014, history);
	siv.addAuthor(straede);
	siv.addAuthor(larsen);

	Biography ike("Ike - an American hero", 2007);
	ike.addAuthor(korda);

	Biography hst("Truman", 1992);
	hst.addAuthor(mcc);

	Biography jfk("Kennedy", 2003);
	jfk.addAuthor(dallek);

	MyBooks mb("Oles Bøger");
	mb.addPublication(dff);
	mb.addPublication(l);
	mb.addPublication(uml);
	mb.addPublication(cpp);
	mb.addPublication(siv);
	mb.addPublication(ike);
	mb.addPublication(jfk);
	mb.addPublication(hst);
	
	mb.findNonFictionWithMoreThanOneAuthor();
	mb.findPubsWithNonFictionTopic("Programming");

	return 0;
}
