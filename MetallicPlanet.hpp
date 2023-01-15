#ifndef METALLICPLANET_H
#define METALLICPLANET_H
#include "Planet.hpp"

#pragma once

class MetallicPlanet : public Planet
{
public:
    MetallicPlanet();
    MetallicPlanet(const int silver, const int gold, const int platinum, const int rarite, const int sRarium);
     virtual ~MetallicPlanet() = default;

private:

};

#endif