#include "RockyPlanet.hpp"

RockyPlanet::RockyPlanet(int silver, int gold, const int platinum, const int rarite, const int sRarium)
        : Planet {silver, gold, platinum, rarite, sRarium} {
                type = 'R';
}

RockyPlanet::RockyPlanet() {
        type = 'R';
        std::vector<int> minVec {10, 5, 1, 0, 0};
        std::vector<int> maxVec {50, 20, 10, 5, 0};
        //Set the min+Max number of each resource for this type of planet
        Planet::SetResourceLimits(minVec, maxVec);
        const std::vector<int> sellPriceInput {2, 4, 10, 25, 100};
        Planet::SetSellPrice(sellPriceInput);
      
}