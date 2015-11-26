#pragma once
#include <iostream>
using namespace std;

class Broek
{
public:
	Broek();
	Broek(int enT, int enN);

	int getTaeller();
	int getNaevner();
	Broek adder(Broek enB);
	Broek subtraher(Broek enB);
	Broek multiplicer(Broek enB);
	Broek divider(Broek enB);

	Broek operator+(Broek enB);
	Broek operator-(Broek enB);
	Broek operator*(Broek enB);
	Broek operator/(Broek enB);

	~Broek();

private:

	int taeller;
	int naevner;
};


