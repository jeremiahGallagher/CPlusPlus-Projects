//PC 11
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void selectionSort(string array[], const int SIZE);


int main()
{
	const int NUM_NAMES = 20;
	string presNames[NUM_NAMES];

	
	ifstream inputFile;
inputFile.open("Presidents.txt");

for(int i = 0; i < NUM_NAMES; i++)
{
getline(inputFile,presNames[i]);
}
	selectionSort(presNames, NUM_NAMES);

	inputFile.close();

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
