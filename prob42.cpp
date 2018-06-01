// This progam averages a set of numbers.
#include <iostream>
using namespace std;

int main()
{
	int numCount, total;
	double average;

	cout << "How many numbers do you want to average? ";
	cin >> numCount;
	for(int count = 0; count < numCount; count++)
	{
		int num;
		cout << "Enter a number: ";
		cin >> num;
		total += num;
		count++;
	}
	average = total / numCount;
	cout << "The average is " << average << endl;
	return 0;
}