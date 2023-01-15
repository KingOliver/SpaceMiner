#include "Platinum.hpp"

Platinum::Platinum()
    : Resource {"Platinum", 10} {
}

const int Platinum::getValue(){
    return Resource::getValue();
}

const std::string Platinum::getName(){
    return Resource::getName();
}