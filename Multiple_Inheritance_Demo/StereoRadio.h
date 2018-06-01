// StereoRadio.h

#ifndef STEREORADIO_H
#define STEREORADIO_H

#include"Radio.h"

class StereoRadio : public  Radio{

private:

	bool stereo;

public:

	static const bool STEREO_ON = true;
	static const bool STEREO_OFF = false;
	StereoRadio();
	StereoRadio(double station);
	StereoRadio(double station, bool stereo);

	void setStereo(bool stereo);

	void doSomething();

};


#endif