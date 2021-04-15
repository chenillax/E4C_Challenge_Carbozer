#ifndef __VIEW__
#define __VIEW__
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include "video.hpp"
#include "user.hpp"

class View {
    private :
    int user;
    std::string name;
    Terminal terminal ;
    Quality quality ;
    Stream stream ;
    Localisation localisation ;
    Video video;

    public: 
    //Constructor
    View(int user, std::string name, Terminal terminal, Quality quality, Stream stream, Localisation localisation,Video video);
    //returns the consommed data with this quality (GB/hours)
    double data_per_hours(); 
    //returns the consomation per data with this stream (kWh/GB)
    double kwh_per_go(); 
    //returns the consomation  depending on the country (gCO2eq/kWh)
    double cotwo_per_kwh(); 
    //returns the emission carbon of one video (considering only the visionning) (gCO2eq)
    double emission_by_watching();
    //returns the carbon cost of the video shared by all the viewers(gCO2eq)
    double emission_shared();
    //return the total emission (gCO2eq)
    double total_emission();
};

#endif