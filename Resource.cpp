#include "Resource.hpp"

Resource::Resource(const std::string name, int value)
    : name{name}, value{value}{

}

const int Resource::getValue(){
    return value;
}

const std::string Resource::getName(){
    return name;
}

void Resource::ChangeCargo(const int i){
    inCargo += i;
}

const int Resource::GetCargo(){
    return inCargo;
}