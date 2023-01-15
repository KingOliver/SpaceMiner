#include "Planet.hpp"

Planet::Planet(){
    type = 'p';
}

Planet::Planet(const int silver, const int gold, const int platinum, const int rarite, const int sRarium)
{
    resources.push_back(silver);
    resources.push_back(gold);
    resources.push_back(platinum);
    resources.push_back(rarite);
    resources.push_back(sRarium);
}

void Planet::MinePlanet(){
    
}

const std::vector<int>* Planet::GetResourcesVec(){
    return &resources;
}

const int Planet::GetResource(const int i){
    return resources[i];
}

void Planet::SetResources(std::vector<int> &r){
    resources = r;
}

const char Planet::GetType(){
    return type;
}

void Planet::SetResourceLimits(std::vector<int> minVec, std::vector<int> maxVec){
    int vecSize = minVec.size();
    for (int i =0; i < vecSize; i++){
        resourceMin.push_back(minVec[i]);
        resourceLimit.push_back(maxVec[i]);
    }
    return;
}

std::vector<std::vector<int>> Planet::GetResourceRange(){
    std::vector<std::vector<int>> combVec;
    combVec.push_back(resourceMin);
    combVec.push_back(resourceLimit);
    return combVec;
}

void Planet::SetSellPrice(const std::vector<int> &sellPriceInput){

    sellPrice = sellPriceInput;

}

int Planet::GetSellPrice(const int i){
    return sellPrice[i];

}