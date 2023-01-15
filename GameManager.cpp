#include "GameManager.hpp"
#include <cstdlib> 
#include <ctime>
#include <iostream>

void GameManager::PlayGame(){
    AddResourcesToVec();

    Player *player = CreateCharacter();
    IntroText(player);
    while (!fin){
        GamePlayLoop(player);
    }

}

void GameManager::IntroText(Player* player) const{
    std::cout << "Hello Cpt." << player->GetName() << std::endl << "You start with 1000 credits, you will need to find planets, scan them and choose to mine or move on" << std::endl << "You can store a limited amount of resources which you can sell or discard" << std::endl << "Game will now Start";
    std::cout << "\n\n\n\n\n";
}

Player* GameManager::CreateCharacter(){
    std::cout << "Welcome to Space Trader..." << std::endl << "Please enter name : ";
    std::string name;
    std::cin >> name;
    Player *player = new Player(name);
    return player;
}

void GameManager::GamePlayLoop(Player* player){
    Planet *p = GeneratePlanet();
    bool scanChoice = BoolUserChoice("Scan Planet", 50);
    if (scanChoice){
        std::cout << "Proceeding with Planet Scan" << std::endl;
        ScanPlanet(p);
        bool mineChoice = BoolUserChoice("Mine Planet", 100);
            if (mineChoice){
                std::cout << "Proceeding with Planet Mining Operation" << std::endl;
                MinePlanet(p);
            }
    }
    bool showCargo = BoolUserChoice("view cargo", 0);
    if (showCargo){
        ShowCargo();
        bool sellCargo = BoolUserChoice("sell cargo", 0);
        if (sellCargo){
            SellCargo(p);
        }
    }
}

void GameManager::AddResourcesToVec(){

    Silver *silver = new Silver();
    resourceObjVec.push_back(silver);
    Gold *gold = new Gold();
    resourceObjVec.push_back(gold);
    Platinum *platinum = new Platinum();
    resourceObjVec.push_back(platinum);
    Rarite *rarite = new Rarite();
    resourceObjVec.push_back(rarite);
    Superarium *superarium = new Superarium();
    resourceObjVec.push_back(superarium);
    resourceVecSize = resourceObjVec.size();
    return;
}


Planet* GameManager::GeneratePlanet(){
    //To be changed
    std::cout << "Searching For Planets..." << std::endl;
    srand((unsigned)time(0));
    int type = rand()%10;
    if (type < 5){
        Planet *p = new RockyPlanet();
        std::cout << "Rocky Planet Found!" << std::endl;
        return p;
    } else if (type > 4 && type < 8) {
        Planet *p = new MetallicPlanet();
        std::cout << "Metallic Planet Found!" << std::endl;
        return p;
    }
    Planet *p = new EarthLikePlanet();
    std::cout << "Earth-Like Planet Found!" << std::endl;
    return p;

}

const bool GameManager::BoolUserChoice(std::string s, int value){
    char input {' '};
    while (input != 'y' || input != 'n'){
        std::cout << "y/n : Would you like to " << s << "? ";
        if (value > 0){
            std::cout << "This will cost " << value << std::endl;
        }
        std::cin >> input;
        std::cout << std::endl;
        switch (input){
            case 'y' :
            {
                return true;
            }
            case 'n' :
            {
                return false;
            }
            default :
            {
                std::cout << "Invalid Input" << std::endl;
            }
        }
    }
    return false;
}

const int GameManager::MultiUserChoice(const int limit){
    int option;
    std::cin >> option;
    return option;

}

void GameManager::ScanPlanet(Planet *p){
    
    srand((unsigned)time(0)); 
    std::vector<int> resourceNumbers(resourceVecSize);
    std::cout << "Resources found!" << std::endl;
    std::vector<std::vector<int>> rangeVec = p->GetResourceRange();

    for (int i = 0; i < resourceVecSize; i++){

        int check = (rangeVec[1][i]) - (rangeVec[0][i]);
        check == 0 ? resourceNumbers[i] = 0 : resourceNumbers[i] = (rand()%check);
        //resourceNumbers[i] = (rand()% ((rangeVec[1][i]) - (rangeVec[0][i])));
        resourceNumbers[i] += rangeVec[0][i];
        std::cout << resourceObjVec[i]->getName() << " : " << resourceNumbers[i] << std::endl;
    }
    p->SetResources(resourceNumbers);

    return;

}


void GameManager::MinePlanet(Planet *p){
    int option;
    std::cout << "You can either mine 100% of 1 resource or 75% of 2 resources, what would you like to mine?" << std::endl;
    std::cout << "1 - mine 1 resource" << std::endl;
    std::cout << "2 - mine 2 resources" << std::endl;
    std::cin >> option;
    switch (option){
        case 1:
        {
            int r1 = SelectResource("", p);
            std::cout << "Mining " << p->GetResource(r1) << " " << resourceObjVec[r1]->getName() << std::endl;
            resourceObjVec[r1]->ChangeCargo(p->GetResource(r1));
            break;
        }
        case 2:
        {
            int r1 = SelectResource("1st ", p);
            //add 0.5 to ensure rounding up
            int r1p = ((p->GetResource(r1)/100.0) * 75.0) + 0.5;
            int r2 = SelectResource("2nd ", p);
            int r2p = ((p->GetResource(r2)/100.0) * 75.0) + 0.5;
            //std::cout << "r1p : " << r1p << std::endl << " r2p : " << r2p << std::endl; 
            std::cout << "Mining " << r1p << " " << resourceObjVec[r1]->getName() << std::endl;
            std::cout << "Mining " << r2p << " " << resourceObjVec[r2]->getName() << std::endl;
            resourceObjVec[r1]->ChangeCargo(r1p);
            resourceObjVec[r2]->ChangeCargo(r2p);
            break;
        }
    }
}

const int GameManager::SelectResource(const char *s, Planet *p){
    int input;
    std::cout << "Select " << s << "resource to mine." << std::endl;
    //print to console the resources and options
    while (true){
        for (int i = 0; i < resourceVecSize; i++){
            std::cout << i+1 << " : " << resourceObjVec[i]->getName() << " : " << p->GetResource(i) << std::endl;
        }
        std::cin >> input;
        std::cout << std::endl;
        //check input is within valid range
        if (input > 0 && input < (resourceVecSize+1)){
            return input-1;
        } else {
            std::cout << "Invalid Input" << std::endl;
        }
    }
}

void GameManager::ShowCargo(){
    std::cout << "Cargo contains :" << std::endl;
    for (int i =0; i < resourceVecSize; i++){
        std::cout << resourceObjVec[i]->getName() << " : " << resourceObjVec[i]->GetCargo() << std::endl;
    }
}

void GameManager::SellCargo(Planet* p, Player player){
    int input;
    bool check = true;
    std::cout << "Please select cargo to sell" << std::endl;
    std::cout << "Option : Resource : Value" << std::endl;
    for (int i =0; i < resourceVecSize; i++){
        std::cout << (i+1) << " : " << resourceObjVec[i]->getName() << " : " << p->GetSellPrice(i) << std::endl;
        if (i == (resourceVecSize - 1)){
            std::cout << i+2 << " : " << "Exit" << std::endl;
        }
        
    }
    while (check){
        std::cin >> input;
        std::cout << std::endl;
        //check input is within valid range
        if (input > 0 && input < (resourceVecSize+2)){
            if (input != 6) {
                //Get amount in cargo and then empty for that resource
                input--;
                int cargoAmount = resourceObjVec[input]->GetCargo();
                resourceObjVec[input]->ChangeCargo(cargoAmount);
                int valueTotal = p->GetSellPrice(input) * resourceObjVec[input]->GetCargo();
                player.ChangeMoney(valueTotal);
                break;
            } else {
                return;
            }
            
            
        } else {
            std::cout << "Invalid Input" << std::endl;
        }
    }
    
}