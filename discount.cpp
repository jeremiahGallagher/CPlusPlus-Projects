 #include <iostream>
using namespace std;
int main (){

float units, total, discount;

float const COST = 99;

cout << "How many units were sold?" << endl;
cout << "Please enter an amount greater than zero" << endl;
cin >> units;

if(units <= 0)
	cout << "That amount is not greater than zero" << endl;

else if (units >=1 && units <= 9)
	{discount = units * COST * 1;}

else if (units >=10 && units <= 19)
	{discount = units * COST * .20;}

else if (units >=20 && units <= 49)
	{discount = units * COST * .30; }

else if (units >=50 && units <= 99)
	{discount = units * COST * .40;}

else if (units >= 100)
	{discount = units * COST * .50;}

total = units * COST - discount;
cout << "The total is " << total << endl;

return 0;}



