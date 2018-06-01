//pc 11
#include <iostream>
using namespace std;

void getScore(int &score);
void calcAverage(int num1, int num2, int num3, int num4, int num5);
int findLowest(int score1, int score2, int score3, int score4, int score5);



int main()
{
	int score1, score2, score3, score4, score5;
	// calls getScore function 5 times to retrieve and store 5 test scores
	getScore(score1);
	getScore(score2);
	getScore(score3);
	getScore(score4);
	getScore(score5);
	//calls calcAverage function to which calls dropLowest and calculates average score of 4 highest scores
	calcAverage(score1, score2, score3, score4, score5);

	return 0;
}

// requests test scores 5 times from user
void getScore(int &score)
{

	do
	{
	cout << "Enter a test score between 0 - 100: " << endl;
	cin >> score;
	}
	while(score > 100 || score < 0);
}
// finds lowest score of 5 test scores and returns value to calcAverage
int findLowest(int score1, int score2, int score3, int score4, int score5)
{

	int lowest = min(score1, min(score2, min(score3, min(score4, score5))));

return lowest;
}
//calls findLowest then calculates average
void calcAverage(int num1, int num2, int num3, int num4, int num5)
{
	int lowest;
	double average;
	double dropped;
	lowest = findLowest(num1, num2, num3, num4, num5);

	dropped = num1 + num2 + num3 + num4 + num5 - lowest;

	average = dropped / 4;

	cout << "The average of the 4 highest scores is: " << average << endl;
}
	
