#include "user.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>


/**********************/
/*      TERMINAL     */
/*********************/
Terminal::Terminal(Terminal_device device): device(device){
}
double Terminal :: emission_per_hours(){
    double eph = 0;
    switch (device){
        case Terminal_device::Phone:
            eph = 20;
            break;
        case Terminal_device::ChromeCast:
            eph = 160;
            break;
        case Terminal_device::Pc:
            eph = 90 ;
            break;
        case Terminal_device::Tablet:
            eph =  210;
            break;
    }
    return eph ;
}






