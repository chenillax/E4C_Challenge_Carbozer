#ifndef __USER__
#define __USER__
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

/* The differents enumerations we need to our algortithm */
enum class Terminal_device { Phone, Pc, ChromeCast, Tablet};
enum class Quality { Auto, p144, p240, p360,p480,p720,p1080};
enum class Stream { Wifi, Net};
enum class Localisation {France, Germany, Spain, GreatBritain, Italy,Norway, Sweden,Poland,Belgium,Portugal};

class Terminal {
    public: 
    Terminal_device device;
    public :
    Terminal(){};
    Terminal(Terminal_device device);
    //returns the embedded emission of the device 
    double embedded_emission();
    //returns the emission the device consumes (gC02eq/hours) (We chose thant the "auto mode" is the mean of each quality.)
    double emission_per_hours(); 
};


#endif





