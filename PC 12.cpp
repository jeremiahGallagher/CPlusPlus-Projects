#include <iostream>
#include <string>

using namespace std;


int main()
{
	const int STUNUMS = 5;
	const int STUTEST = 4;
	string name[5];
	char grades[5];

	double nums[STUNUMS][STUTEST];
	double total = 0;
	double average = 0;
	for(int i = 0; i < STUNUMS; i ++)
	{
		
		for(int j = 0; j < STUTEST; j++)
		{
			cout << "Please enter the student's name: " << endl;
			getline(cin, name[j]);
			do
			{
			cout << "Please enter the grade for test # " << j + 1 << endl;
			cin >> nums[i][j];
			}
			while(nums[i][j] <= 0);
			total += nums[i][j];

		}

	average = total / 4;


	
			

	return 0;
}
