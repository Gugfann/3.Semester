#include "Persistens.h"



Persistens::Persistens()
{
}

void Persistens::writeToFile(string aText)
{
	ofstream outFile("Test.txt");
	outFile << aText;
	outFile.close();
}

void Persistens::writePersonToFile(Person aPerson)
{
	ofstream outFile("Person.txt");
	outFile << aPerson.getName() << "#" << aPerson.getNationality() << "#" << aPerson.getYOB() << "#" << aPerson.getYOD() << "#";
	outFile.close();
}

string Persistens::loadFromFile()
{
	string input;

	ifstream inFile("Test.txt");
	
	while(inFile.good())
	{
		input += inFile.get();
	}

	return input;
}

Person Persistens::loadPersonFromFile()
{
	ifstream inFile("Person.txt");
	vector<string> fileContent;
	string temp;


	while (inFile.good())
	{
		
		char currentChar = inFile.get();
		if (currentChar == '#')
		{
			fileContent.push_back(temp);
			temp = "";
		}
		else
		{
			temp += currentChar;
		}
	}

	string tempName = fileContent[0];
	string tempNat = fileContent[1];
	int tempYOB = stoi(fileContent[2]);
	int tempYOD = stoi(fileContent[3]);

	Person tempPerson(tempName,tempNat,tempYOB,tempYOD);
	return tempPerson;
}

	Persistens::~Persistens()
{
}
