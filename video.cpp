#include "video.hpp"

double Video::get_duration(){return duration;}

std::string Video::get_name(){return name;}

int Video::get_view_prediction(){return view_prediction;}

Video::Video(std::string name, int emission_creation, int view_prediction,double duration) : name(name), emission_creation(emission_creation),view_prediction(view_prediction), duration(duration){
    datacenter = DataCenter();}

double Video::emission(){
    return emission_creation + (3.54*duration)*datacenter.emission();
}

