#ifndef PLANET_H
#define PLANET_H
#include <vector>
#include <iostream>

#pragma once

class Planet
{
public:
    Planet();
    Planet(const int silver, const int gold, const int platinum, const int rarite, const int sRarium);
    virtual ~Planet() = default;
    virtual const std::vector<int>* GetResourcesVec();
    virtual void MinePlanet();
    virtual const char GetType();
    virtual void SetResourceLimits(std::vector<int> minVec, std::vector<int> maxVec);
    virtual std::vector<std::vector<int>> GetResourceRange();
    virtual void SetResources(std::vector<int> &r);
    virtual const int GetResource(const int i);
    virtual void SetSellPrice(const std::vector<int> &sellPriceInput);
    virtual int GetSellPrice(const int i);
private:
    std::vector<int> resources;
    std::vector<int> sellPrice;
protected:
    std::vector<int> resourceMin;
    std::vector<int> resourceLimit;

    char type;
};

#endif