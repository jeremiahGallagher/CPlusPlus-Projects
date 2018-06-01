/* 
 * Author: Jeremiah Gallagher
 *
 * Class: CS 2363, Spring 2017, Monday 530-800pm
 *
 * Assignment: Week 1- Roman Numeral / Decimal Conversion
 * 
 * Summary: The program asks user to enter either a Roman Numeral or a Decimal number
 * using the provided format.  The program then converts Roman to Decimal or
 * Decimal to Roman accordingly.
 *
 */
 
#include <iostream>
#include <string>

using namespace std;

//Function prototypes
int convertRomantoDecimal(string s);
void convertDecimalToRoman(string s);
bool isDecimal(string s);
void capitalize(string & s);
bool isRoman(string s);
int decValue(char roman);

int main()
{
	int userChoice = 0;
	string s;
	bool isValid = true;
	
	do{
		//Introduce program and prompt user to choose a conversion method or exit. Read user input.
		cout << endl;
		cout << "This Program is designed to convert a Roman Numeral to a Decimal, or a Decimal to a Roman Numeral" << endl;
		cout << "Please choose option 1, 2, or 3." << endl;
		cout << "1.) Roman Numeral to Decimal." << endl;
		cout << "2.) Decimal to Roman Numeral." << endl;
		cout << "3.) Exit." << endl;
		cin >> userChoice;
		cin.ignore();
	
		switch(userChoice){
			
			case 1 :
			cout << "You have decided to convert a Roman Numeral to a Decimal. Please enter a Roman Numeral.  Do not include numbers, special characters, or spaces: " << endl;
			getline(cin, s);
			capitalize(s);
			if(isRoman(s) == true){
			int result = convertRomantoDecimal(s);
			cout << "(Roman Numeral) " << s << " == (Decimal) " << result << endl;
			}
			else {
				cout << "That is not a properly formatted input.  Goodbye" << endl;
				isValid = false;
			} 
			break;
			
			case 2 :
			cout << "You have decided to convert a Decimal to a Roman Numeral. Please enter a positive number from 1-9999. Do not include any special characters or spaces: " << endl;
			getline(cin, s);
			if(isDecimal(s) == true){
			convertDecimalToRoman(s);
			}
			else {
				cout << "That is not a properly formatted input.  Goodbye" << endl;
				isValid = false;
			}
			break;
			
			case 3 :
			cout << "Thank you for using the converter. Goodbye." << endl;
			return 0;
			break;
			
			default :
			cout << "That was not one of the available choices. Goodbye." << endl;
			return 0;
			  
		}
		userChoice = 0;

	} while(isValid);
	
	return 0;
	
}
//Function definitions

//Check if string holds content, then loop through string to verify it holds characters between 1 & 9, inclusive. 
bool isDecimal(string s) {
    if(s.size() == 0){
		return false;
	}
	
	for(size_t i = 0;i < s.size();i++) {
        if((s[i]>='0' && s[i]<='9')==false) {
            return false;
        }
    }
    return true;
}

//Convert Decimal to Roman by first converting string to int, then comparing int digits/place values and adding Roman chars accordingly.
// This solution is discussed and demonstrated on programminghelporg youtube channel, uploaded apr 15, 2012
void convertDecimalToRoman(string s){
	int num = stoi(s);
	int ref = num;
	string rom;
	int p;
	
	// Processes thousands place and concatenates string with appropriate Roman characters
	if (num >= 1000){
		p = ( num / 1000);
		for (int i = 0; i < p; i++){
			rom += 'M';
		}
		num %= 1000; //Removes thousands and leaves remaining 
	}
	// Processes hundreds place and concatenates string with appropriate Roman characters
	if (num >= 100){
		p = (num / 100);
		if (p == 9){
			rom += "CM";
		}
		else if (p >= 5){
			rom += 'D';
			for(int i = 0; i < p - 5; i++){
				rom += 'C';
			}
		}
		else if (p == 4){
			rom += "CD";
		}
		else if (p >= 1){
			for(int i = 0; i < p; i++){
				rom += 'C';
			}
		}
		num %= 100; // Removes hundreds and leaves remaining
	}
	// Processes tens place and concatenates string with appropriate Roman characters
	if (num >= 10){
		p = (num / 10);
		if (p == 9){
			rom += "XC";
		}
		else if (p >= 5){
			rom += 'L';
			for (int i = 0; i < p - 5; i++){
				rom += 'X'; 
			}
		}
		else if (p == 4){
			rom += "XL";
		}
		else if(p >= 1){
			for (int i = 0; i < p; i++)
			{
				rom += 'X';
			}
		}
		num %= 10; //Removes tens and leaves remaining
	}
	//Processes ones place and concatenates string with appropriate Roman characters
	if (num >= 1){
		p = num;
		if (p == 9){
			rom += "IX";
		}
		else if (p >= 5){
			rom += 'V';
			for (int i = 0; i < p - 5; i ++){
				rom += 'I';
			}
		}
		else if (p==4){
			rom += "IV";
		}
		else if (p >= 1){
			for (int i = 0; i < p; i++){
				rom += 'I';
			}
		}
	}
		cout << "(Decimal) " << ref << " == (Roman Numeral) " << rom << endl;
}

//Capitalize inputted string for format consistency using toupper function
void capitalize(string & s){
	for (size_t i = 0; i < s.length(); ++i){
		s[i] = toupper(s[i]);
	}
}

//verify input is only made of valid roman characters using find_first_not_of
bool isRoman( string s){
	string romChars = "IVXLCDM";
	string input = s;
	if (input.find_first_not_of(romChars) == string::npos){
		return true;
	}
	else{
		return false;
	}
}

//Converts Roman character to its decimal equivalent
int decValue(char roman){
	switch(roman){
		case 'I':return 1;
		case 'V':return 5;
		case 'X':return 10;
		case 'L':return 50;
		case 'C':return 100;
		case 'D':return 500;
		case 'M':return 1000;
	}
}

//Converts Roman to Decimal by iterating through input from right to left, adding and subtracting as necessary.
//This solution was discussed by Ashish Singh on youtube channel Codewhoop, uploaded on Dec. 2, 2016.
int convertRomantoDecimal(string s){
	int n = s.length()-1;
	int ans = 0, p = 0;
	for(int i = n; i >= 0; i--){
		if(decValue(s[i]) >= p ){
			ans += decValue(s[i]);
		}
		else{
			ans -= decValue(s[i]);
		}
		p = decValue(s[i]);
	}
	return ans;
}

	
	





	
