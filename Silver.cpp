#include "Silver.hpp"

Silver::Silver()
    : Resource {"Silver", 1} {
}

const int Silver::getValue(){
    return Resource::getValue();
}

const std::string Silver::getName(){
    return Resource::getName();
}