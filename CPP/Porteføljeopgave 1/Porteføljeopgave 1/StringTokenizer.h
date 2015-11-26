#pragma once
#include <string>
#include <iostream>
using namespace std;

class StringTokenizer
{
public:
	StringTokenizer();
	StringTokenizer(const string& source);
	StringTokenizer(const string& source, const string& delimiters);

	bool isDelimiter(char tegn);
	bool hasMoreTokens();
	string nextToken();
	string nextToken(const string& delimiters);
	int countTokens();
	void printTokens();

	string getTekst();
	int getIndeks();
	string stringBoolean(bool enB);

	~StringTokenizer();

private:
	string delim;
	int indeks;
	string tekst;
};

