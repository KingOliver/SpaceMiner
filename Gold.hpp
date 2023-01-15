#ifndef GOLD_H
#define GOLD_H
#include "Resource.hpp"

#pragma once

class Gold : public Resource
{
public:
    Gold();
    virtual ~Gold() = default;
    virtual const int getValue();
    virtual const std::string getName();
private:

};

#endif