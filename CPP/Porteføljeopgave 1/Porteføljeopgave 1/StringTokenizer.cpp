#include "StringTokenizer.h"


StringTokenizer::StringTokenizer()
{
	tekst = "N/A";
	delim = "\n";
	indeks = 0;
}

StringTokenizer::StringTokenizer(const string& source)
{
	tekst = source;
	delim = "\n";
	indeks = 0;
}

StringTokenizer::StringTokenizer(const string& source, const string& delimiters)
{
	tekst = source;
	delim = delimiters;
	indeks = 0;
}

bool StringTokenizer::isDelimiter(char character)
{
	for (int i = 0; i < delim.length(); i++)
	{
		if (character == delim[i])
			return true;
	}
	return false;
}

bool StringTokenizer::hasMoreTokens()
{
	int charsLeft = tekst.length() - indeks - 1; // resterende tegn i tekst.

	if (indeks <= tekst.length() - 1)
	{
		for (int i = 1; i <= charsLeft; i++)
			if (!isDelimiter(tekst[indeks + i])) // kontrollerer om der er tegn efter indeks der ikke er delimiters
				return true;
	}
	return false;
}

string StringTokenizer::nextToken()
{
	string token = "";

	if (hasMoreTokens() == true)
	{
		if (isDelimiter(tekst[indeks]) == true) // er nuværende karakter en delimiter?
		{
			while (isDelimiter(tekst[indeks]) == true && indeks <= tekst.length() - 1) // næste karakter der ikke er en delimiter skal findes
				indeks++;
		}

		while (isDelimiter(tekst[indeks]) == false && indeks <= tekst.length() - 1) // indeks øges så længe karakteren ikke er en delimiter og indeks ikke peger udenfor teksten.
		{
			token.push_back(tekst[indeks]);
			indeks++;
		}

		return token;

	}

	return "";
}

string StringTokenizer::nextToken(const string & delimiters)
{
	delim = delimiters;
	return nextToken();
}

int StringTokenizer::countTokens()
{
	int tokenCount = 0;
	while (indeks <= tekst.length() - 1)
	{
		if (hasMoreTokens() == false)
			break;
		nextToken();
		tokenCount++;
	}
	indeks = 0;
	return tokenCount;
}

void StringTokenizer::printTokens()
{
	int tokenCount = countTokens();
	int* indeksPointer = &indeks;
	int* tokenCountPointer = &tokenCount;
	string* delimPointer = &delim;
	string* tekstPointer = &tekst;

	for (int i = 0; i < tokenCount; i++)
	{
		cout << "Token " << i+1 << ": " << nextToken() << endl;
	}

	cout << endl << endl;

	indeks = 0;
}

string StringTokenizer::getTekst()
{
	return tekst;
}

int StringTokenizer::getIndeks()
{
	return indeks;
}

string StringTokenizer::stringBoolean(bool enB)
{
	return enB == 0 ? "Nope" : "Yup";
}

StringTokenizer::~StringTokenizer()
{
}
