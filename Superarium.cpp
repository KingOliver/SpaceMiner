#include "Superarium.hpp"

Superarium::Superarium()
    : Resource {"Superarium", 50} {
}

const int Superarium::getValue(){
    return Resource::getValue();
}

const std::string Superarium::getName(){
    return Resource::getName();
}