#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include "user.hpp"
#include "datacenter.hpp"
#include "view.hpp"
#include "video.hpp"

int main(){
    //First Example : Sylvain watching Squeezie's FAQ
    DataCenter datacenter = DataCenter();
    std::string name_video = "CECI EST UNE FOIRE AUX QUESTIONS #2 (FAQ Squeezie)";
    Video video = Video(name_video,3800, 6000000,0.23);
    
    std::string name = "Sylvain";
    Terminal terminal = Terminal(Terminal_device::Phone);
    Quality quality = Quality::p1080;
    Stream stream = Stream ::Net;
    Localisation localisation = Localisation::France;
    View sylvain = View(1, name, terminal, quality, stream,localisation,video);
    std::cout << name << " emitted " << sylvain.emission_by_watching() << " gCO2eq while watching "<< name_video << ".\n The carbon cost of the video shared with the viewer is "<< sylvain.emission_shared() << "\nFinally "<< name << " emitted "<< sylvain.total_emission() <<" gCO2eq \n"<< std::endl;
    std::cout << video.get_name() << "emitted " << video.emission() << "gC02eq for its creation" << std::endl;
    
    //Second Example : Natascha listenned to "Alors,Alors" on Youtube
    //DataCenter datacenter;
    name_video = "Alors,Alors";
    video = Video(name_video,26000000,36000000,0.07);
    name = "Natascha";
    terminal = Terminal(Terminal_device::Pc);
    quality = Quality::Auto;
    stream = Stream ::Wifi;
    localisation = Localisation::Germany;
    View natascha = View(1, name, terminal, quality, stream,localisation,video);
    std::cout << name << " emitted " << natascha.emission_by_watching() << " gCO2eq while watching "<< video.get_name() << ".\n The carbon cost of the video shared with the viewer is "<< natascha.emission_shared() << "gCO2eq.\n Finally "<< name << " emitted "<< natascha.total_emission() <<" gCO2eq.\n"<< std::endl;
    std::cout << video.get_name() << "emitted " << video.emission() << "gC02eq for its creation" << std::endl;
    
   return 0;
}