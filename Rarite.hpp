#ifndef RARITE_H
#define RARITE_H
#include "Resource.hpp"

#pragma once

class Rarite : public Resource
{
public:
    Rarite();
    virtual ~Rarite() = default;
    virtual const int getValue();
    virtual const std::string getName();
private:

};

#endif