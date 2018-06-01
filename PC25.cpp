#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ifstream inputFile;
	string name;
	int group1 = 0, group2 = 0, group3 = 0, group4 = 0, group5 = 0;
	inputFile.open("LineUp.txt");

	if(!inputFile)
	{
	cout << "File Not Found!" << endl;
	}
	
	else
	{
		while(inputFile >> name)
		{
	
		if(name[0] == 'A' || name[0] == 'B' || name[0] == 'C' || name[0] == 'D' || name[0] == 'E' || name[0] == 'F')
		{
			group1++;
		}
		else if(name[0] == 'G' || name[0] == 'H' || name[0] == 'I' || name[0] == 'J' || name[0] == 'K') 
			{
				group2++;
		}
		else if(name[0] == 'L' || name[0] == 'M' || name[0] == 'N' || name[0] == 'O' || name[0] == 'P' || name[0] == 'Q')
		{
			group3++;
		}
		else if(name[0] == 'R' || name[0] == 'S' || name[0] == 'T' || name[0] == 'U' || name[0] == 'V')
		{
			group4++;
		}
		else if(name[0] == 'W' || name[0] == 'X' || name[0] == 'Y' || name[0] == 'Z')
		{
			group5++;
		}
	}
	}

	cout << setw(5) << "A-F" << setw(5) << "G-K" << setw(5) << "L-Q" << setw(5) << "R-V" << setw(5)  << "W-Z" << endl;
	cout << setw(5) << group1 << setw(5) << group2 << setw(5) << group3 << setw(5) << group4 << setw(5)  << group5 << endl;

	inputFile.close();

	return 0;
}

