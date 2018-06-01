/*        Author: Jeremiah Gallagher
 *        Advanced C++
 *        Monday 5:30 pm
 *        Spring 2017
 *
 *Summary: Palindrome Validator: This program asks user for a string.
 *         It then copies all alpha-numeric characters into a new string.
 *         It checks the new string to see if it meets requirements for
 *         palindromes.  If then displays whether or not it is a palindrome.
 */

#include <iostream>
#include <string>

using namespace std;

//function protocols
string stringBuilder (string & source);
bool isPalindrome(string & destination);

int main(){

	string source;
	
	cout << "Welcome to the Palindrome Validation tool" << endl;
	cout << "Please enter a word or phrase to validate: " << endl;
	getline(cin, source);
	
	string destination = stringBuilder(source);

	if(isPalindrome(destination)){
		cout << source << " is a palindrome!" << endl << endl;
		cout << "I see it as " << destination << endl;
	}
	else{
		cout << destination << " is not a palindrome!" << endl << endl;
		cout << "I see it as " << destination << endl;
	}
	
	return 0;
}

// Function to copy and capitalize only alpha-numeric characters from source string into a new string
string stringBuilder (string & source){
	string newString;

	for(size_t i = 0; i < source.length(); i++){
		if(isalnum(source[i])){
			newString += toupper(source[i]);
		}
	}

	return newString;
}
// Function that uses recursive logic to test for palindrome symmetry
bool isPalindrome (string & dest){
	if(dest.length() <= 1 ){
		return true;
	}
	return (dest[0] == dest[dest.length()-1] && isPalindrome(dest.substr(1, dest.length() - 2)));
}