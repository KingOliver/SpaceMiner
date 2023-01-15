#include "Player.hpp"

Player::Player(std::string name)
        : name{name} {

}

Player::~Player()
{

}

std::string Player::GetName(){
    return name;
}

void Player::ChangeMoney(int value){
    money += value;
}