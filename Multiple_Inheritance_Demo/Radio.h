// Radio.h

#ifndef RADIO_H
#define RADIO_H

class Radio{

private:

	double theStation;
	

public:

	Radio();
	Radio(double);

	double getStation();
	void setStation(double);

	void doSomething();
};




#endif
