//PC 13 Days Out
#include <iostream>
using namespace std;


int numEmployees();
int daysMissed(int);
double calc(int , int);


int main()
{
 double average = 0;
 int numberOfEmployees = numEmployees();
 int totalDays = 0;


  totalDays = daysMissed(numberOfEmployees);

  average = calc(numberOfEmployees, totalDays);

  cout << "The average number of absent days is: " << average << endl;
  return 0;
}

int numEmployees()
{
	int num = 0;
	while(num < 1)
	{
		cout << "How many employees are in the company?" << endl;
	cin >> num;
	}
	return num;
}

int daysMissed(int employees)
{
	int days = 0;
	int total = 0;
	int counter = 0;
	
		for(counter = 0; counter < employees; counter++)
		{
			cout << "How many days did employee # " << counter + 1 << " miss?" << endl;
			cin >> days;
			
			while(days < 0)
			{
				cout << "Invalid input.  Please enter a positive number." << endl;
				cin >> days;
			}
			total += days;
		}
	return total;
}

double calc(int numEmployees, int days)
{
	double average = days / static_cast<double>(numEmployees);
	return average;
}
