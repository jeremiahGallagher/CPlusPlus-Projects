/*        Author: Jeremiah Gallagher
 *        Advanced C++
 *        Monday 5:30 pm
 *        Spring 2017
 *
 *Summary: This program asks user for a space delimited string of ints and operators.
 *         It uses split() to parse the string into a vector while removing spaces
 *         It then uses postfixed() to iterate through the vector of strings and compare
 *         Against characters representing operators. If operator, pops stack twice, performs
 *         operation and then pushes result onto stack. If not an operator, assumes it 
 *        is an int and converts to int and pushes onto stack. Finally, displays myStack[0]
 *        which is the element containing the answer.
 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;

void split (string & input, vector<string>& v);
void postfixed(vector<string>& result, vector<int> & myStack);

int main(){

	string input;

	cout << "This is the Postfix Notation Calculator!" << endl;

	//performs operations until user inputs 0.
	while( input != "0"){
	
		vector <int> myStack;
		vector <string> result;

		
		cout << "Please enter a Postfix expression.  Or, enter 0 to quit." << endl;
		getline(cin, input);
		
		split(input, result);

		postfixed(result, myStack);

		cout << myStack[0] << endl;

		cin.clear();
		
	}

	cout << "Thank you for using the Postfix Notation Calculator.  Goodbye!";

return 0;
}


//Function to parse string into vector, removing spaces
//This function discussed on string parsing sub forum on stackoverflow.com
void split (string & input, vector<string>& v){
	size_t pos = 0, found;
	while((found = input.find_first_of(' ', pos)) != std::string::npos){
		v.push_back(input.substr(pos, found - pos));
		pos = found + 1;
	}
	v.push_back(input.substr(pos));
}
//function to perform maths and push/pop ints onto stack.
//This solution is discussed on website: http://www.cs.sfu.ca/CourseCentral/125/tjd/postfix.html, accessed on 02/12/2017
void postfixed(vector<string>& result, vector<int> & myStack){
	
	int num1 = 0;
	int num2 = 0;

	for(size_t i = 0; i < result.size(); i++){
		if (result[i] =="+"){
			num1 = myStack.back();
			myStack.pop_back();
			num2 = myStack.back();
			myStack.pop_back();
			myStack.push_back(num1 + num2);
		}
		else if(result[i] =="-"){
			num1 = myStack.back();
			myStack.pop_back();
			num2 = myStack.back();
			myStack.pop_back();
			myStack.push_back(num2 - num1);
		}
		else if(result[i] =="*"){
			num1 = myStack.back();
			myStack.pop_back();
			num2 = myStack.back();
			myStack.pop_back();
			myStack.push_back(num2 * num1);
		}
		else if(result[i] =="/"){
			num1 = myStack.back();
			myStack.pop_back();
			num2 = myStack.back();
			myStack.pop_back();
			myStack.push_back(num2 / num1);
		}
		else if(result[i] =="%"){
			num1 = myStack.back();
			myStack.pop_back();
			num2 = myStack.back();
			myStack.pop_back();
			myStack.push_back(num2 % num1);
		}
		else{
			myStack.push_back(stoi(result[i]));
		}


		
	}
}