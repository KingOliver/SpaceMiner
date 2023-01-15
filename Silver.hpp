#ifndef SILVER_H
#define SILVER_H
#include "Resource.hpp"

#pragma once

class Silver : public Resource
{
public:
    Silver();
    virtual ~Silver() = default;
    virtual const int getValue();
    virtual const std::string getName();
private:

};

#endif