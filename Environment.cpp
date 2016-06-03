#include "Environment.h"

Environment::Environment(){
    // The time the environment was created
    initCreateTime = (osGetTime() / 10) / 60;

    // The time it is right now
    time = osGetTime() - initCreateTime;

    // Environments start out in Spring and you brace for the rest of the seasons
    season = "Spring";

    // The world starts out beautiful and sunny
    weather = "Sunny";
}

std::string Environment::getSeason(){
    return season;
}

void Environment::setSeason(std::string newSeason){
    season = newSeason;
}

int Environment::getTime(){
    return time;
}


int Environment::getWaterAvailable(){
  return waterAvailable;
}
