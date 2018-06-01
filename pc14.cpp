//PC 14
#include<iostream>   
#include<iomanip>
#include<string>
using namespace std;

int main ()
{
	//establish rates
	string month, year;
	float sales, stateTax, countyTax, totalTax, total;
	stateTax = .04;
	countyTax = .02;
	totalTax = stateTax + countyTax;
	
	//get user input
	cout << "What is the month? " << endl;
	getline(cin, month);
	cout << "What is the Year? " << endl;
	getline(cin, year);
	cout << "What is the total amount collected at the register? " << endl;
	cin >> total;
	//establish sales before taxes
	sales = total/1.06;
	//display the sales figures
	cout << "Year: " << year << endl;
	cout << "Month: " << month << endl;
	cout << "-----------------------" << endl;
	cout << setprecision(2) << fixed;
	cout << setw(20) << left << "Total Collected:" << setw(3) << "$" << setw(10) << right << total << endl;
	cout << setw(20) << left << "Sales:" << setw(3) <<"$" << setw(10) << right << sales << endl;
	cout << setw(20) << left << "County Sales Tax:" << setw(3) << "$" << setw(10) << right << countyTax * sales << endl;
	cout << setw(20) << left << "State Sales Tax:" << setw(3) << "$" << setw(10) << right << stateTax * sales << endl;
	cout << setw(20) << left << "Total Sales Tax:" << setw(3) << "$" << setw(10) << right << totalTax * sales << endl;

	return 0;
}
