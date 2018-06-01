//pc 15
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	float weight, distance, rate;
	bool badWeight = false; //flag
	bool badDistance = false;  //flag
	// collect weight from user
	cout << "We only ship packages between 1-20 Kilograms" << endl;
	cout << "What is the weight of the package?" << endl;
	cin >> weight;
		if(weight <=0 || weight > 20)
			badWeight = true; //changes flag state for invalid input

	//collect distance from user
    cout << "Enter a Distance between 10 and 3000 miles: " << endl;
	cin >> distance;
	
	 if(distance < 10 || distance > 3000)
		badDistance = true; //changes flag state for invalid input
   // divides distance into 500 mile increments
    else if(distance > 500)
		distance = distance / 500;
	else distance = 1;


	//decides range of weight and then calculates rate by using calculalted distance
	if(weight <= 2)
		rate = 1.1 * distance;
	else if(weight > 2 && weight < 7)
		rate = 2.2 * distance;
	else if(weight > 6 && weight < 11)
		rate = 3.7 * distance;
	else if(weight > 10 && weight < 21)
		rate = 4.8 * distance;

	//checks flag(s) state and outputs either error message or resulting cost
	if(badWeight == true)
		cout << "Invalid Weight Entered." << endl;
	else if(badDistance == true)
		cout << "Invalid Distance Entered. " << endl;
	else
	cout << setprecision(2) << fixed << "The cost to ship is: $" << rate << endl;

	return 0;
}

