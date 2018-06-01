// PC 12: Celcius to Fahrenheit Table
#include <iostream>
using namespace std;

int main()
{
	float C,F;

	cout << "Celcius  Fahrenheit" << endl;
	cout << "-------------------" << endl;

	for(C=0; C <= 20; C++)
	{
		F = C * 9 / 5 + 32;
		cout << C << "\t" << F << endl;
	}
	return 0;
}
