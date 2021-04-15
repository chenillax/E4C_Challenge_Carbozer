#ifndef __VIDEO__
#define __VIDEO__
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include "datacenter.hpp"

class Video{
    public:
    std::string name;
    double emission_creation ;
    int view_prediction;
    double duration; //en hours
    DataCenter datacenter; 

    public :
    //Constructors
    Video(std::string name, int emission_creation, int view_prediction, double duration);
    Video(){};
    //Getters
    double get_duration();
    std::string get_name();
    int get_view_prediction();
    //returns the emission due to the creation of the video and its storage (gCO2eq)
    double emission();


};

#endif