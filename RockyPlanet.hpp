#ifndef ROCKYPLANET_H
#define ROCKYPLANET_H
#include "Planet.hpp"

#pragma once

class RockyPlanet : public Planet
{
public:
    RockyPlanet();
    RockyPlanet(int silver, int gold, const int platinum, const int rarite, const int sRarium);
    virtual ~RockyPlanet() = default;

private:

};

#endif