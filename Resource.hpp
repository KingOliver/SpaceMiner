#ifndef RESOURCE_H
#define RESOURCE_H
#include <iostream>
#include <string>

#pragma once

class Resource
{
public:
    Resource(std::string name, int value);
    //virtual ~Resource() = default;
    virtual const std::string getName();
    virtual const int getValue();
    void ChangeCargo(const int i);
    const int GetCargo();
protected:
    const std::string name;
    int value;
    unsigned int inCargo = 0;
};

#endif