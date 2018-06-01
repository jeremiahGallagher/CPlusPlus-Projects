// This program adds two numbers entered by the user.
#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	char again = 'y';  //char wasn't initialized to 'y' or 'Y' to start loop

	while(again == 'y' || again == 'Y')
	 {                 //while statements were not enclosed within curly braces
		cout << "Enter a number: ";
	    cin >> num1;
	    cout << "Enter another number: ";
		cin >> num2;
		cout << "Their sum is " << (num1+num2) << endl; // String literal wasnt closed with "
		cout << "Do you want to do this again? ";
			cin >> again;
	}                 //while statements were not enclosed within curly braces
	return 0;
}
