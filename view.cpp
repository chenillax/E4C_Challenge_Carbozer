#include "view.hpp"

double View :: data_per_hours(){
    double data = 0;
    switch (quality){
        case Quality::Auto :
            data = 0.466; //a mean of all
            break;
        case Quality::p1080 :
            data =1;
            break;
        case Quality::p144 :
            data =0.133;
            break;
        case Quality::p240 :
            data =0.222;
            break;
        case Quality::p360 :
            data =0.333;
            break;
        case Quality::p480 :
            data =0.444;
            break;
        case Quality::p720 : 
            data =0.666;
            break;
    }
    return data;
}
double View ::kwh_per_go(){
    double kwh = 0;
    if (stream == Stream::Net){
        kwh = 0.62 ;
    

    }
    else {
        kwh = 0.09;


    }

    return kwh;
}

double View::cotwo_per_kwh(){
    double cotwo  = 0 ;
    switch(localisation){
        case Localisation::Belgium:
            cotwo = 264 ;
            break;
        case Localisation ::France :
            cotwo = 54 ;
            break;
        case Localisation ::Germany :
            cotwo = 450 ;
            break;
        case Localisation::GreatBritain :
            cotwo = 295 ;
            break;
        case Localisation ::Italy :
            cotwo = 443;
            break;
        case Localisation ::Norway :
            cotwo = 39;
            break;
        case Localisation ::Poland :
            cotwo = 777 ;
            break;
        case Localisation ::Portugal :
            cotwo = 342 ;
            break;
        case Localisation :: Spain :
            cotwo = 249;
            break;
        case Localisation :: Sweden :
            cotwo = 54;
            break;
    }
    return cotwo;
}

View :: View(int user, std::string name, Terminal terminal, Quality quality, Stream stream, Localisation localisation, Video video):
    user(user),name(name),terminal(Terminal(terminal.device)),quality(quality),stream(stream),localisation(localisation),video (Video(video.name,video.emission_creation,video.view_prediction,video.duration)){}



double View :: emission_by_watching(){
    double emission_terminal_per_hours = terminal.emission_per_hours();
    double emission_terminal = emission_terminal_per_hours * video.get_duration();
    double data_p_h = data_per_hours();
    double data = data_p_h * video.get_duration();
    double kwh = data * kwh_per_go();
    double cotwo = kwh*cotwo_per_kwh();
    return cotwo + emission_terminal;
}

double View::emission_shared(){
    return video.emission()/(video.get_view_prediction());
}

double View::total_emission(){
    return emission_by_watching() + emission_shared();
}
