//OcccPerson.h

//Jeremiah Gallagher
//Advanced C++
//Mon 530-800pm
//Spring 2017

#ifndef OCCCPERSON_H
#define OCCCPERSON_H

#include "Person.h"
#include "OCCCDate.h"

class OcccPerson : public Person{

private:

	string STUDENT_ID;


public:

	//Constructors
	OcccPerson(string lastName, string firstName, OCCCDate dob, string STUDENT_ID);
	OcccPerson(Person p, string STUDENT_ID);

	string getStudentID();







};


#endif
