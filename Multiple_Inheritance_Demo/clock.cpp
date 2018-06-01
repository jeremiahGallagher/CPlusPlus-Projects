//clock.cpp

//Jeremiah Gallagher
//Advanced C++
//Mon 530-800pm
//Spring 2017
//Multiple Inheritance Demo

#include <iostream>
#include "Clock.h"
using namespace std;

static const int DEFAULT_CLOCK_TIME = 1200;

Clock::Clock(){  //scope resolution
	theTime = DEFAULT_CLOCK_TIME;
}

Clock::Clock(int theTime){
	this->theTime = theTime;
}

int Clock::getTime(){
	return theTime;
}
void Clock::setTime(int theTime){
	this->theTime = theTime;
}

void Clock::doSomething(){
	cout << "Clock is doing something..." << endl;
}
