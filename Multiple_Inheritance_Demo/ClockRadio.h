// ClockRadio.h

#ifndef CLOCKRADIO_H
#define CLOCKRADIO_H

#include "Clock.h"
#include "StereoRadio.h"

class ClockRadio : public Clock, public StereoRadio{
public:
	ClockRadio();
	ClockRadio(int theTime, double theStation);
	void doSomething();

};

#endif