#include "MetallicPlanet.hpp"

MetallicPlanet::MetallicPlanet(int silver, int gold, const int platinum, const int rarite, const int sRarium)
        : Planet {silver, gold, platinum, rarite, sRarium} {
                type = 'M';
}

MetallicPlanet::MetallicPlanet(){
        type = 'M';
        std::vector<int> minVec {20, 10, 2, 0, 0};
        std::vector<int> maxVec {100, 40, 20, 0, 0};
        //Set the min+Max number of each resource for this type of planet
        Planet::SetResourceLimits(minVec, maxVec);
        const std::vector<int> sellPriceInput {1, 2, 5, 100, 250};
        std::cout << "setting Sell Price" << std::endl;
        Planet::SetSellPrice(sellPriceInput);
}