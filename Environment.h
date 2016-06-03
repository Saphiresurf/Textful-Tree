#ifndef Environment_H
#define Environment_H

// Class defining the season, weather, and conditions the tree is surrounded by
class Environment
{
  public:
    Environment();

    std::string getSeason();

    void setSeason(std::string newSeason);

    int getTime();

    int getWaterAvailable();

    int absorbWater();

  private:
    int initCreateTime;

    int time;

    // Water available can be absorbed by the tree, part of it
    // Will be lost to the environment while the tree absorbs it.
    // I suppose this should have a maximum, but maybe we'll introduce flooding
    // Floor = 0; Ceiling = ???
    int waterAvailable;

    // Values: Spring/Summer/Fall/Winter
    std::string season;

    // Values: Sunny, Raining, Snowing, Misty, and Hailing
    std::string weather;
};

#endif
