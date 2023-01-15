#include "EarthLikePlanet.hpp"

EarthLikePlanet::EarthLikePlanet(int silver, int gold, const int platinum, const int rarite, const int sRarium)
        : Planet {silver, gold, platinum, rarite, sRarium} {
                type = 'E';
}

EarthLikePlanet::EarthLikePlanet() {
        type = 'E';
        std::vector<int> minVec {0, 0, 0, 0, 0};
        std::vector<int> maxVec {30, 10, 5, 10, 1};
        //Set the min+Max number of each resource for this type of planet
        Planet::SetResourceLimits(minVec, maxVec);
        const std::vector<int> sellPriceInput {5, 20, 50, 20, 50};
        Planet::SetSellPrice(sellPriceInput);
}