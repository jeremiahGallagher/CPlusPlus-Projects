#include <iostream>
#include <string>

using namespace std;

int getNumAccidents(string region);
void findLowest(int reg1, int reg2, int reg3, int reg4, int reg5);


int main()
{
	string north, south, east, west, central;
	int reg1, reg2, reg3, reg4, reg5;

	reg1 = getNumAccidents("North");
	reg2 = getNumAccidents("South");
	reg3 = getNumAccidents("East");
	reg4 = getNumAccidents("West");
	reg5 = getNumAccidents("Central");

	findLowest(reg1, reg2, reg3, reg4, reg5);




	return 0;
}


int getNumAccidents(string region)
{
	int numAccidents;
	do
	{
	cout << "How  many auto accidents were reported in the " << region << " last year?" << endl;
	cin >> numAccidents;
	}

	while(numAccidents < 0);

	return numAccidents;
}

	void findLowest(int reg1, int reg2, int reg3, int reg4, int reg5)
	{
		int north = reg1;
		int south = reg2;
		int east = reg3;
		int west = reg4;
		int central = reg5;

		if(north < south && north < east && north < west && north < central)
		{
			cout << "North: " << north << endl;
		}
	    else if(south < north && south < east && south < west && south < central)
		{
			cout << "South: " << south << endl;
		}
		 else if(east < north && south > east && east < west && east < central)
		{
			cout << "East: " << east << endl;
		}
		 else if(west < north && west < south && west < east && west < central)
		{
			cout << "West: " << west << endl;
		}

		  else if(central < north && central < south && central < west && east > central)
		{
			cout << "Central: " << central << endl;
		}

		 /* abetter way is min() method:
		 int lowest = min(north, min(south, min(east, min(west, min(central))));*/
		 /* then compare lowest for smaller expressions*/
	}