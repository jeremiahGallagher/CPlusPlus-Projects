//PC 24
#include <iostream>
#include <string>
using namespace std;
int main ()
{

	string name, age, city, college, profession, animal, petName;

	// collect and store user input

	cout << "Enter your name:" << endl;
	getline(cin, name);
	cout << "Enter your age:" << endl;
	getline(cin, age);
	cout << "Enter a city:" << endl;
	getline(cin, city);
	cout << "Enter a college:" << endl;
	getline(cin, college);
	cout << "Enter a profession:" << endl;
	getline(cin, profession);
	cout << "Name an animal:" << endl;
	getline(cin, animal);
	cout << "Enter a pet name:" << endl;
	getline(cin, petName);

	//Display story with user input

	cout << "There once was a person named " << name << " who lived in " << city <<  "." << endl;
	cout << "At the age of " << age << ", " << name << " went to college at " << college << "." << endl;
	cout << name << " Graduated and went to work as a " << profession << "." << endl;
	cout << "Then " << name << " adopted a(n) " << animal << " named " << petName << "." << endl;
	cout << "They both lived happily ever after!" << endl;

	return 0;
}


	






