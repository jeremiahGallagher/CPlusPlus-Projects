//PC 6
#include <iostream>
#include <string>
using namespace std;

void selectionSort(string array[], const int SIZE);

int main()
{
	const int NUM_NAMES = 20;
	string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim", "Griffin, Jim", "Stamey, Marty", "Rose, Geri", "Taylor, Terri", "Johnson, Jill", "Allison, Jeff", "Looney, Joe",
		"Wolfe, Bill", "James, Jean", "Weaver, Jim", "Pore, Bob", "Rutherford, Greg", "Javens, Renee", "Harrison, Rose", "Setzer, Cathy", "Pike, Gordon", "Holland, Beth"};

	selectionSort(names, NUM_NAMES);

	return 0;
}

void selectionSort(string array[], const int SIZE)
{
	int startScan, minIndex;
	string name;

	for(startScan = 0; startScan < (SIZE -1); startScan++)
	{
		minIndex = startScan;
		name = array[startScan];
		
		for(int index = startScan + 1; index < SIZE; index++)
		{
			if(array[index] < name)
			{
				name = array[index];
				minIndex = index;
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = name;
	}

for (int a = 0; a <= SIZE; a++)
{
cout << array[a] << endl;
}
}
