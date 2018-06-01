//OcccPerson.cpp

//Jeremiah Gallagher
//Advanced C++
//Mon 530-800pm
//Spring 2017

#include <iostream>
#include "Person.h"
#include "OCCCDate.h"
#include "OcccPerson.h"

using namespace std;

OcccPerson::OcccPerson(string lastName, string firstName, OCCCDate dob, string STUDENT_ID) :Person(lastName,  firstName, dob){
	this->STUDENT_ID = STUDENT_ID;

}

OcccPerson::OcccPerson(Person p, string STUDENT_ID) :Person(lastName,  firstName, dob)  {
	this->STUDENT_ID = STUDENT_ID;
}