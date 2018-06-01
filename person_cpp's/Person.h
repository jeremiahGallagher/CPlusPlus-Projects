//Person.h

//Jeremiah Gallagher
//Advanced C++
//Mon 530-800pm
//Spring 2017

#ifndef PERSON_H
#define PERSON_H

#include "OCCCDate.h"

class Person{

private:
	//private data
	string firstName;
	string lastName;
	OCCCDate dob;

	//private functions
	bool equalsIgnoreCase(string s1, string s2); //helper function for equals
	string toUpperCase(string s);

public:

	//Constructors
	Person(string lastName, string firstName);
	Person(string lastName, string firstName, OCCCDate dob);

	//Public Getters
	string getFirstName();
	string getLastName();
	OCCCDate getDate();
	
	//Public Setters
	void setLastName(string lastName);
	void setFirstName(string firstName);

	int getAgeInYears();
	bool equals(Person p);
	string toString();

};

#endif
	

	



		



