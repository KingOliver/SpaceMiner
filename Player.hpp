#ifndef PLAYER_H
#define PLAYER_H
#include <string>

#pragma once

class Player
{
public:
    Player(std::string name);
    ~Player();
    std::string GetName();
    void ChangeMoney(int value);

private:

    std::string name;
    unsigned int money{1000};
    unsigned int cargoSpace{50};

};

#endif