#include "Broek.h"

int main()
{
	Broek x(1, 2);
	Broek y(1, 2);
	Broek z;

	z = x + y;

	cout << z.getTaeller() << endl;
	cout << "-" << endl;
	cout << z.getNaevner() << endl << endl;
}