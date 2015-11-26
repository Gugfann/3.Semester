#include "DirectForm2.h"
#include <fstream>
#include <iostream>

int main()
{
	vector<double> bc1{ 0.01031,0.06188,0.1547,0.2063,0.1547,0.06188,0.01031 };
	vector<double> ac1{ 1,-1.188,1.305,-0.6743,0.2635,-0.05175,0.005023 };

	vector<double> bc2{ 1,2.164,1 };
	vector<double> ac2{ 1,-0.3219,0.0424 };

	vector<double> bc3{ 1,2.2854,1.4720 };
	vector<double> ac3{ 1,-0.3701,0.1962 };

	vector<double> bc4{ 1,1.5526,0.6793 };
	vector<double> ac4{ 1,-0.4959,0.6041 };

	vector<double> bc5{0.0103};
	vector<double> ac5{1};

	DirectForm2 H1(ac1, bc1);
	DirectForm2 H2(ac2, bc2);
	DirectForm2 H3(ac3, bc3);
	DirectForm2 H4(ac4, bc4);
	DirectForm2 H5(ac5, bc5);

	vector<double> impFunction(40, 0);
				   impFunction[0] = 1;
	vector<double> impOut;

	vector<double> stepFunction(40,1); 
	vector<double> cascadeStep;
	
	for (size_t i = 0; i < stepFunction.size() - 1; i++)
	{
		double result = H2.Filter(stepFunction[i]);
		       result = H3.Filter(result);
			   result = H4.Filter(result);
			   result = H5.Filter(result);

		cascadeStep.push_back(result);
	}
		
	ofstream outStep("OutStep.txt");

	for (size_t i = 0; i < cascadeStep.size(); i++)
	{
		outStep << cascadeStep[i] << '\n';
	}
	outStep.close();

	for (size_t i = 0; i < impFunction.size() - 1; i++)
	{
		impOut.push_back(H1.Filter(impFunction[i]));
	}

	ofstream outImp("OutImp.txt");

	for (size_t i = 0; i < impOut.size(); i++)
	{
		outImp << impOut[i] << '\n';
	}
	outImp.close();


	return 0;
}