//StereoRadio.cpp

#include <iostream>
#include "StereoRadio.h"
using namespace std;

static const bool DEFAULT_STEREO_SETTING = false;


StereoRadio::StereoRadio():Radio(){
	stereo = DEFAULT_STEREO_SETTING;
}

StereoRadio::StereoRadio(double station) : Radio(station){
	stereo = DEFAULT_STEREO_SETTING;
}

StereoRadio::StereoRadio(double station, bool stereo):Radio(station){
	this->stereo = stereo;
}

void StereoRadio:: setStereo(bool){

}

void doSomething();