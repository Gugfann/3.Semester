#include "DirectForm2.h"

DirectForm2::DirectForm2()
{
}

DirectForm2::DirectForm2(vector<double> denCoeff, vector<double> numCoeff)
{
	bCoeff = numCoeff;
	aCoeff = denCoeff;

	if (bCoeff.size() < aCoeff.size())
	{
		int diff = aCoeff.size() - bCoeff.size();
		for (int i = 0; i < diff; i++)
			bCoeff.push_back(0);
	}

	if (bCoeff.size() > aCoeff.size())
	{
		int diff = bCoeff.size() - aCoeff.size();
		for (int i = 0; i < diff; i++)
			aCoeff.push_back(0);
	}
	
	for (int i = 0; i < bCoeff.size(); i++)
	{
		previousStuff.push_back(0);
	}
}

double DirectForm2::Filter(double n)
{
	double wn = n;

	if (previousStuff.size() > 1)
	{
		for (int i = 1; i < previousStuff.size(); i++)
		{
			wn += -aCoeff[i] * previousStuff[i];
		}
	}

	double tempWn = wn;

	wn *= bCoeff[0];

	if (previousStuff.size() > 1)
	{
		for (int i = 1; i < previousStuff.size(); i++)
		{
			wn += bCoeff[i] * previousStuff[i];
		}

		for (int i = 0; i < previousStuff.size() - 2; i++)
		{
			int indeks = previousStuff.size() - 1 - i;

			previousStuff[indeks] = previousStuff[indeks - 1];
		}

		previousStuff[1] = tempWn;
	}
	return wn;
}

DirectForm2::~DirectForm2()
{
}
