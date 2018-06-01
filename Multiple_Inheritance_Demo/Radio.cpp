//clock.cpp

//Jeremiah Gallagher
//Advanced C++
//Mon 530-800pm
//Spring 2017
//Multiple Inheritance Demo

#include <iostream>
#include "Radio.h"

using namespace std;
static const double DEFAULT_RADIO_STATION = 99.5;

Radio::Radio(){
	theStation = DEFAULT_RADIO_STATION;
}

Radio::Radio(){
	this->theStation = theStation;
}

double Radio::getStation(){
	return theStation;
}

void Radio::setStation(double theStation){
	this->theStation = theStation;
}

void Radio::doSomething(){
	cout << "Radio is doing something..." << endl;
}

