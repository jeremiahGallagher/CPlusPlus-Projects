// Test.cpp

#include <iostream>
#include "ClockRadio.h"
#include "Clock.h"
#include "Radio.h"
#include "StereoRadio.h"
using namespace std;

int main(){

	Clock c1 = Clock();
	Clock c2 = Clock(1000);
	

	cout << "Clock 1 time is " << c1.getTime() << endl;
	cout << "Clock 2 time is " << c2.getTime() << endl;

	c1.setTime(800);

	cout << "Clock 1 time is " << c1.getTime() << endl;

	c2.doSomething();

	Radio r1 = Radio();
	Radio r2 = Radio(103.7);

	cout << "Radio 1 station is " <<r1.getStation() << endl;
	cout << "Radio 2 station is " <<r2.getStation() << endl;

	r1.setStation(93.1);

	cout << "Radio 1 station is " <<r1.getStation() << endl;

	r2.doSomething();

	StereoRadio sr1 = StereoRadio();
	StereoRadio sr2 = StereoRadio(90.1);
	StereoRadio sr3 = StereoRadio(107.7, false);

	cout << "StereoRadio sr1 station is " << sr1.getStation() << endl;
	cout << "StereoRadio sr2 station is " << sr2.getStation() << endl;
	cout << "StereoRadio sr3 station is " << sr3.getStation() << endl;

	sr1.setStereo(sr1.STEREO_ON);



	return 0;
}