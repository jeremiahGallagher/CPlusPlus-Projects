//PC 14 Bank Charges
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	float balance = 0;
	float charge = 10;
	float checks = 0;
	bool overDraft = false;
	bool noChecks = false;


	// ask user for balance
	cout << "What is your beginning balance?" << endl;
	cin  >> balance;
	if (balance <= 0)
		overDraft = true;

	else if(balance < 400)
		charge += 15;
	else
		charge = charge;
	
	
	cout << "How many checks did you write?" << endl;
	cin >> checks;
	if(checks < 0)
		noChecks = true;
	
    if(checks > 0 && checks < 20)
		charge = charge + checks * .10;
	     
    else if(checks > 19 && checks < 40)
		charge = charge + checks * .08;
	   
	else if(checks > 39 && checks < 60)
		charge = charge + checks * .06;
	   
	else if(checks >= 60)
		charge = charge + checks * .04;
	  
	else 
		cout << "That is an invalid amount" << endl;

	if(overDraft == true)
		cout << "Warning! Your account is OverDrawn!" << endl;
	else if(noChecks == true)
		cout << "Check count cannot be negative" << endl;
	else
		cout << setprecision(2) << fixed << "Your fees are: $" << charge << endl;
	return 0;
}