//PC 2
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

void backward(char phrase[], const int SIZE);

int main()
{
	const int SIZE = 50;
	char phrase[SIZE];
	

	cout << "Please enter a phrase less than " << (SIZE - 1) << " characters in length" << endl;;
	cin.get(phrase, SIZE);
	

	backward(phrase, SIZE);


	return 0;
}


void backward(char phrase[], const int SIZE)
{

int length = strlen(phrase);

for(int i = length; i >=0; i--)
{

	cout << phrase[i];
	
}
cout  << endl;
}