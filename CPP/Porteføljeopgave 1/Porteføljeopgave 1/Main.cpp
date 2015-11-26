#include "StringTokenizer.h"

int main()
{
	StringTokenizer test("Gid du var i Skanderborg og blev der, kære Peter.   .!!..,,  ", " ,.!");

	cout << "Text: " << endl << test.getTekst() << endl << endl;
	cout << "Character count: " << test.getTekst().length() << endl;
	cout << "Token count: " << test.countTokens() << endl << endl;
	test.printTokens();



	while (true)
	{
		string newInput;
		string newDelimiter;
		cout << endl << "Enter new text: " << endl << endl;

		getline(cin, newInput);

		cout << endl << "Enter delimiters: " << endl << endl;

		getline(cin, newDelimiter);

		StringTokenizer userInput(newInput, newDelimiter);

		cout << endl << "Text: " << endl << userInput.getTekst() << endl << endl;
		cout << "Character count: " << userInput.getTekst().length() << endl;
		cout << "Token count: " << userInput.countTokens() << endl << endl;
		userInput.printTokens();		
	}
	
	return 0;
}