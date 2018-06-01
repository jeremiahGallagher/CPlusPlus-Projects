// PC 12: Celcius to Fahrenheit Table
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float C,F;

	cout << "Celcius  Fahrenheit" << endl;
	cout << "-------------------" << endl;

	for(C=0; C <= 20; C++)
	{
		F = C * 9 / 5 + 32;
		cout << setprecision(2) << fixed;
		cout  << setw(8) << right <<  C << setw(8) << right <<  F << endl;
	}
	return 0;
}