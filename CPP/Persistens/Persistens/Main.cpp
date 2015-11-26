#include "Persistens.h"
#include "Person.h"

int main()
{
	Person kristian("Kristian Møller Hansen", "Danmark", 1987, 0);
	Persistens Test;

	Test.writeToFile("Numerical base (radix) that determines the valid characters and their interpretation.If this is 0, the base used is determined by the format in the sequence (see strtol for details). Notice that by default this argument is 10, not 0.");
	Test.writePersonToFile(kristian);
	
	cout << Test.loadFromFile() << endl << endl;
	
	Person Mutanten = Test.loadPersonFromFile();

	cout << "Mutantnavn: " << Mutanten.getName() << endl;
	cout << "Mutantland: " << Mutanten.getNationality() << endl;
	cout << "Mutantfoedsel: " << Mutanten.getYOB() << endl;
	cout << "Mutantdoed: " <<  Mutanten.getYOD() << endl;
	
	return 0;
}