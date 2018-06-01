//OCCCDate.h

//Jeremiah Gallagher
//Advanced C++
//Mon 530-800pm
//Spring 2017

#ifndef OCCCDATE_H
#define OCCCDATE_H

class OCCCDate{

  private:

    int dayOfMonth;
    int monthOfYear;
    int year;
    bool dateFormat;

  public:

    OCCCDate(); 
    OCCCDate(int day, int month, int year);
    int getDayofMonth(); 
	int getMonth();
    string getNameOfMonth(); 
    int getYear(); 
    int getDifference(OCCCDate d1, OCCCDate d2);
    int getDifference(OCCCDate d);
    void setDateFormat(bool df);
    bool equals(OCCCDate d);
    string toString();
};

#endif  
