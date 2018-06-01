// PC 8 Coin Toss
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int coinToss();


int main()
{
	// get the system time.
	unsigned int seed = time(0);

	// Seed random number generator.
	srand(seed);

	
	int userChoice;
	int counter;
	int result;
	int heads = 0;
	int tails = 0;
	// ask user how many times to execute coin toss
	cout << "Welcome to Coin Toss" << endl;
	cout << "How many times would you like to flip the coin?" << endl;
	cin >> userChoice;

	 // decide heads or tails for each iteration.
	for(counter = 0; counter < userChoice; counter++)
	{
		result = coinToss();
		if(result == 1)
		{
			cout << "Flip # " << counter + 1 << " is Heads " << endl;
			heads++;
		}
		else
		{
			cout << "Flip # " << counter + 1 << " is Tails " << endl;
			tails++;
		}
	
		
	}
		cout << "******************" << endl;
		cout << "Total Heads was:  " << heads << endl;
		cout << "Total Tails was:  " << tails << endl;

	return 0;
}

// coin toss function generates a number but limited to 1 or 0.
int coinToss()
{
    int num;   
    
    num = rand() % 2 + 1;  
   
    return num;
}


