#pragma once
#include <vector>
using namespace std;

class DirectForm2
{
public:
	DirectForm2();
	DirectForm2(vector<double> denCoeff, vector<double> numCoeff);
	double Filter(double n);
	~DirectForm2();
protected:
	vector<double> aCoeff;
	vector<double> bCoeff;
	vector<double> previousStuff;
};

