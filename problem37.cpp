#include <iostream>
using namespace std;

int main ()

{
	int num;
	int count = 10;
	int commaTrack=-1;

	for(num = 0; num <= count; num++)
		{
			commaTrack +=10;

		if (commaTrack < 100)
			cout << num*10 << ",";
		else 
			cout << num*10 << endl;
	}
	return 0;
}