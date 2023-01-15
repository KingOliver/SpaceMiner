#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "Player.hpp"
#include "Planet.hpp"
#include "RockyPlanet.hpp"
#include "MetallicPlanet.hpp"
#include "EarthLikePlanet.hpp"
#include "Resource.hpp"
#include "Silver.hpp"
#include "Gold.hpp"
#include "Platinum.hpp"
#include "Rarite.hpp"
#include "Superarium.hpp"
#include <iostream>

#pragma once

class GameManager
{
public:
    void PlayGame();
    void IntroText(Player* player) const;
    Player* CreateCharacter();
    void GamePlayLoop(Player* player);
    void AddResourcesToVec();
    const bool BoolUserChoice(std::string s, int value);
    const int MultiUserChoice(const int limit);
    Planet* GeneratePlanet();
    void ScanPlanet(Planet *p);
    void MinePlanet(Planet *p);
    const int SelectResource(const char *s, Planet *p);
    void ShowCargo();
    void SellCargo(Planet* p);
private:
    std::vector<Resource*> resourceObjVec;
    std::vector<char> PlanetTypes {'R', 'M', 'E'};
    bool fin {false};
    int resourceVecSize;
    // r = rocky, m = metalic, e= earthlike
};

#endif