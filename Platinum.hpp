#ifndef PLATINUM_H
#define PLATINUM_H
#include "Resource.hpp"

#pragma once

class Platinum : public Resource
{
public:
    Platinum();
    virtual ~Platinum() = default;
    virtual const int getValue();
    virtual const std::string getName();
private:

};

#endif