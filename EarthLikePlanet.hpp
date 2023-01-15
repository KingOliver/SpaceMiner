#ifndef EARTHLIKEPLANET_H
#define EARTHLIKEPLANET_H
#include "Planet.hpp"

#pragma once

class EarthLikePlanet : public Planet
{
public:
    EarthLikePlanet();
    EarthLikePlanet(int silver, int gold, const int platinum, const int rarite, const int sRarium);
    virtual ~EarthLikePlanet() = default;

private:

};

#endif