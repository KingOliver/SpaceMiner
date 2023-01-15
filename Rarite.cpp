#include "Rarite.hpp"

Rarite::Rarite()
    : Resource {"Rarite", 20} {
}

const int Rarite::getValue(){
    return Resource::getValue();
}

const std::string Rarite::getName(){
    return Resource::getName();
}