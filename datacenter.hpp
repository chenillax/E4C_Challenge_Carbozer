#ifndef __DATACENTER__
#define __DATACENTER__
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

class DataCenter{
    private :
    std::string name;
    public:
    DataCenter();
    double emission(); // return the embbded emission for one GB for a data center (gCO2eq/GB)
    };
#endif