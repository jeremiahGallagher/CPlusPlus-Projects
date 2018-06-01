// PC 10 Drivers License Examination
#include < iostream>
using namespace std;

int main()
{
	const int SIZE = 20;
	char correctAnswers[SIZE] = {'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D', 'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B'};
	char studentAnswers[SIZE];


	for(int i = 0; i < SIZE; i++)
	{
		cout << "Please enter the student's answer for question number # " << i + 1 << endl;
		cout << "Only enter letters A-D" << endl;
		cin >> studentAnswers[i];
		
		while (studentAnswers[i] != 'A' && studentAnswers[i] != 'a' && studentAnswers[i] != 'B' && studentAnswers[i] != 'b' && studentAnswers[i] != 'C' && studentAnswers[i] != 'c' && studentAnswers[i] != 'D' && studentAnswers[i] != 'd')
			{
				cout << "Please enter only letters A, B C, or D" << endl;
			cin >> studentAnswers[i];
			}	
			
		if(studentAnswers[i] == 'a')
			studentAnswers[i] = 'A';
		else if(studentAnswers[i] == 'b')
			studentAnswers[i] = 'B';
		else if(studentAnswers[i] == 'c')
			studentAnswers[i] = 'C';
		else if(studentAnswers[i] == 'd')
			studentAnswers[i] = 'D';
	}

	int incorrect = 0;
	
	for(int j = 0; j < SIZE; j++)
	{
		if(correctAnswers[j] != studentAnswers[j])
		{
			incorrect += 1;
		}
}

if(incorrect > 5)
{
	cout << "Sorry, you only scored " << 20 - incorrect << " out of 20. You failed the test" << endl;
}

else
	cout << "Hooray! You scored " << 20 - incorrect << " out of 20. You passed!" << endl;

cout << "You answered " << 20 - incorrect << " Correctly and " << incorrect << " incorrectly." << endl;

for(int x = 0; x < SIZE; x++)
{
	if(correctAnswers[x] != studentAnswers[x])
	{
		cout << "You incorrect question # " << x+1 << endl;
	}
}
		return 0;
}