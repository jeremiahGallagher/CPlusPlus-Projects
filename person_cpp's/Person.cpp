//Person.cpp

//Jeremiah Gallagher
//Advanced C++
//Mon 530-800pm
//Spring 2017

#include <iostream>
#include "Person.h"
#include "OCCCDate.h"

using namespace std;

Person::Person(string lastName, string firstName){
	this->lastName = lastName;
	this->firstName = firstName;
}

Person::Person(string lastName, string firstName, OCCCDate dob){
	this->lastName = lastName;
	this->firstName = firstName;
	this->dob = dob;
}

string Person::getFirstName(){
	return firstName;
}

string Person::getLastName(){
	return lastName;
}

void Person::setFirstName(string firstName){
	this->firstName = firstName;
}

void Person::setLastName(string lastName){
	this->lastName = lastName;
}

OCCCDate Person::getDate(){
	return dob;
}






