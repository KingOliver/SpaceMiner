#ifndef SUPERARIUM_H
#define SUPERARIUM_H
#include "Resource.hpp"

#pragma once

class Superarium : public Resource
{
public:
    Superarium();
    virtual ~Superarium() = default;
    virtual const int getValue();
    virtual const std::string getName();
private:

};

#endif