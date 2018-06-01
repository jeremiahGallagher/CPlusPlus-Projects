// PC 24. Rock, paper, scissors.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int compPick();

void result(int num1, int num2);

int userPick();



int main()
{

// get the system time.
	unsigned int seed = time(0);

	// Seed random number generator.
	srand(seed);

	
	compPick();
	int compNum = compPick();
	

	cout << "Let's Play Rock, Paper, Scissors: " << endl;



	int userNum=userPick();
	
	while(compNum == userNum)
	{
		cout << "Its a tie. Please pick again" << endl;
		compNum=compPick();
		userNum=userPick();
		
	}
	result(compNum, userNum);

	return 0;
}


int compPick()

{
	//1 is rock, 2 is paper, 3 is scissors for results
    int num;   
    
    num = rand() % 3 + 1;  
   
    return num;
}


int userPick()
{
	int choice;
	cout << "Make your selection: " << endl;
	cout << "1) Rock " << endl;
	cout << "2) Paper " << endl;
	cout << "3) Scissors " << endl;
	cin >> choice;

	while(choice > 3 || choice < 1)
	{
		cout << "Invalid option.  Please choose a number" << endl;
			cin >> choice;
	}
	return choice;
}



void result(int comp, int user)
{
	if(comp == 1 && user == 3)
	{
		cout << "Computer chose Rock. Rock beats scissors. You lose" << endl;
	}
	else if(comp == 2 && user == 1)
	{
		cout << "Computer chose paper. Paper beats rock. You lose" << endl;
	}
	else if(comp == 3 && user == 2)
	{
		cout << "Computer chose scissors. Scissors beats paper. You lose" << endl;
	}
	else if(user == 1 && comp == 3)
	{
		cout << "Computer chose scissors. Rock beats scissors. You win!" << endl;
	}
	else if(user == 2 && comp == 1)
	{
		cout << "Computer chose rock. Paper beats rock. You win!" << endl;
	}
	else if(user == 3 && comp == 2)
	{
		cout << "Computer chose paper. Scissors beats paper. You Win!" << endl;
	}
}