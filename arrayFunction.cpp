#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void calcArray(int numArray[], const int size);

int main()
{

	
	unsigned int seed = time(0);
	srand(seed);

	const int SIZE = 15;
	int nums[SIZE];
	
	calcArray(nums, SIZE);

	return 0;
}

void calcArray(int numArray[], const int size)
{
	int smallest, largest, count = 0;
	double average = 0;

	for(int i = 0; i < size; i++)
	{
		int num = rand() % 3000 + 1;
		numArray[i] = num;
	}


	smallest = numArray[0];
	largest = numArray[0];


	for(int i = 0; i < size; i++)
	{
		
		average += numArray[i];
		count++;

		if(numArray[i] <= smallest)
		{
			smallest = numArray[i];
		}
		 if(numArray[i] >= largest)
		{
			largest = numArray[i];
		 }


	}

	cout << "The smallest is " << smallest << endl;
	cout << "The Largest is " << largest << endl;
	cout << "The average is " << average / count << endl;
	cout << "The total is " << average << endl;

}