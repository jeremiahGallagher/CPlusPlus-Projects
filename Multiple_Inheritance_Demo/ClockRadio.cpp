// ClockRadio.cpp
#include <iostream>
#include "ClockRadio.h"
using namespace std;

ClockRadio::ClockRadio():Clock(), StereoRadio(){

}

ClockRadio::ClockRadio(int theTime, double theStation):Clock(theTime), StereoRadio(theStation){

}

void ClockRadio::doSomething(){
	cout << "ClockRadio is doing something..." << endl;
}