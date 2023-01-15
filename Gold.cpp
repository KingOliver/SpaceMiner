#include "Gold.hpp"

Gold::Gold()
    : Resource {"Gold", 5} {
}

const int Gold::getValue(){
    return Resource::getValue();
}

const std::string Gold::getName(){
    return Resource::getName();
}