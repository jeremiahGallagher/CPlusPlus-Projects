//PC 12
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	const int SIZE = 80;
	int x, length;
	char pword[SIZE];
	bool num = false, up = false, low = false, len = false, spec = false;

	do
	{
		// reset all the booleans
		num = false, up = false, low = false, len = false, spec = false;
		cout << "Please enter a password at least 12 characters long" << endl;
		cout << "Containing at least one numeric, one upper case character" << endl;
		cout << "one lower case character, one special character" << endl;
		cout << "Password: ";
		cin.get(pword,SIZE);

		length = strlen(pword);
		// walk through the password
		for(x = 0;x<length;x++)
		{
			if(length>=12)
				len = true;
			if(isdigit(pword[x]))
				num = true;
			if(isupper(pword[x]))
				up = true;
			if(islower(pword[x]))
				low = true;
			if(ispunct(pword[x]))
				spec = true;
		}

		if(len && num && up && low && spec)
			cout << "Password meets criteria" << endl;
		else
		{
			cout << "Password does not meet criteria" << endl;
			cout << "You failed to have the following" << endl;

			if(!len)
				cout << "Length was only " << length << " needs to be at least 12." << endl;
			if(!num)
				cout << "Missing numeric value" << endl;
			if(!up)
				cout << "Missing upper case character" << endl;
			if(!low)
				cout << "Missing lower case character" << endl;
			if(!spec)
				cout << "Missing special character" << endl;

			cout << endl << endl;
		}
		cin.ignore();
	}while(!len || !num || !up || !low || !spec);


	return 0;
}
