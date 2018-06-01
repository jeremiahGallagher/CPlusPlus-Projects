//Clock.h

#ifndef CLOCK_H
#define CLOCK_H

class Clock{

private:

	int theTime;
	

public:

	Clock();
	Clock(int);
	int getTime();
	void setTime(int);

	void doSomething();
};

#endif