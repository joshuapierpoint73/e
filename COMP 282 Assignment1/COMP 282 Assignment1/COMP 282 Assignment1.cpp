
#include <string.h>
#include <iostream>
#include "Character.h"
#include "Item.h"
#include "Location.h"
#include <algorithm> 
#include <cstdlib>  
#include <time.h> 
using namespace std;
using namespace ch;
using namespace itm;
using namespace loc;

bool compareFunction(Item a, Item b) { return a.getName() > b.getName(); }

int rollDice()
{
    int random = (rand() % 6) + 1;
    return random;
}

Player combat(Player mainChar, Monster monsterInCombat, Location curr)
{
    cout << "\nChar Health:";
    cout << mainChar.getHitPoints();
    cout << "\nMonster Health:";
    cout << monsterInCombat.getHitPoints();
    while (mainChar.getHitPoints() > 0 && monsterInCombat.getHitPoints() > 0)
    {
        int damage = (rollDice() * 2);
        mainChar.takeHit(damage);

        cout << "\n\nYou took ";
        cout << damage;
        cout << " damage";

        if (mainChar.getHitPoints() > 0)
        {
            damage = (rollDice() * 2);
            vector<Weapon> charWeapons = mainChar.getWeapons();
            int size3 = charWeapons.size();
            if (size3 > 0)
            {
                Weapon strongestWeapon = charWeapons[size3 - 1];
                while (size3 - 2 >= 0) {
                    if (charWeapons[size3 - 2].getPower() > strongestWeapon.getPower())
                    {
                        strongestWeapon = charWeapons[size3 - 2];
                    }
                    size3 -= 1;
                }

                damage += strongestWeapon.getPower();


            }

            monsterInCombat.takeHit(damage);
            cout << "\n\nYou dealt ";
            cout << damage;
            cout << " damage";

            cout << "\n\nChar Health:";
            cout << mainChar.getHitPoints();
            cout << "\nMonster Health:";
            cout << monsterInCombat.getHitPoints();
        }
        

        

       
    }
    if (mainChar.getHitPoints() <= 0)
    {
        cout << "\n\nYou died\n\n";
    }
    else
    {
        mainChar.setScore(mainChar.getScore() + 10);
        curr.delMonster(monsterInCombat);
        cout << "\n\nEnemy Slain\n\n";
    }

    

    return mainChar;
}



Player collectItems(Player mainChar,Location curr) 
{
    vector<Potion> locPotions = curr.getPotions();
    int potionVecSize = locPotions.size();
    while (potionVecSize - 1 >= 0) {
        mainChar.addItem(locPotions[potionVecSize - 1]);
        potionVecSize -= 1;
    }

    vector<Weapon> locWeapons = curr.getWeapons();
    int weaponVecSize = locWeapons.size();
    while (weaponVecSize - 1 >= 0) {
        mainChar.addItem(locWeapons[weaponVecSize - 1]);
        weaponVecSize -= 1;
    }

    vector<Treasure> locTreasure = curr.getTreasures();
    int treasureVecSize = locTreasure.size();
    while (treasureVecSize - 1 >= 0) {
        mainChar.addItem(locTreasure[treasureVecSize - 1]);
        treasureVecSize -= 1;
    }
    
    return mainChar;
}


std::string availableExits(Location loc)
{
    vector<pair<std::string,Location>> exits = loc.getExits();
    std::string displayExits;
    int size = exits.size();
    while (size - 1 >= 0) {
      
          displayExits += " " + exits[size - 1].first;
          size -= 1;

    }
   
    return displayExits;
    
}



void areaDescription(Location curr)
{
    cout << "---------------------------------------\n\n";
    cout << "You are in a " + curr.getName() + "\n";
    cout << curr.getDescription() + "\n";
    cout << "Available Exits:" + availableExits(curr) + "\n";
    vector<Weapon> locWeapons = curr.getWeapons();
    int size3 = locWeapons.size();
    while (size3 - 1 >= 0) {
        cout << "There is a " + locWeapons[size3 - 1].getName() + "\n";
        size3 -= 1;
    }
    vector<Potion> locPotions = curr.getPotions();
    size3 = locPotions.size();
    while (size3 - 1 >= 0) {
        cout << "There is a " + locPotions[size3 - 1].getName() + " potion\n";
        size3 -= 1;
    }
    vector<Treasure> locTreasures = curr.getTreasures();
    size3 = locTreasures.size();
    while (size3 - 1 >= 0) {
        cout << "There is a " + locTreasures[size3 - 1].getName() + "\n";
        size3 -= 1;
    }

    vector<Monster> locMonsters = curr.getMonsters();
    size3 = locMonsters.size();
    while (size3 - 1 >= 0) {
        cout << "There is a " + locMonsters[size3 - 1].getName() + "\n";
        size3 -= 1;
    }
    cout << "\n---------------------------------------\n";
}

void inventoryDescription(Player mainChar)
{
    cout << "---------------------------------------\n\n";
    cout << "Health:";
    cout <<  mainChar.getHitPoints();
    vector<Weapon> locWeapons = mainChar.getWeapons();
    cout << "\n\nWeapons:\n";
    std::sort(locWeapons.begin(), locWeapons.end(), compareFunction);
    int size3 = locWeapons.size();
    if (size3 == 0)
    {
        cout << "None\n";
    }
    while (size3 - 1 >= 0) {
        cout << locWeapons[size3 - 1].getName() + "\n";
        size3 -= 1;
    }
    vector<Potion> locPotions = mainChar.getPotions();
    cout << "\nPotions:\n";
    std::sort(locPotions.begin(), locPotions.end(), compareFunction);
    size3 = locPotions.size();
    if (size3 == 0)
    {
        cout << "None\n";
    }
    while (size3 - 1 >= 0) {
        cout << locPotions[size3 - 1].getName() + " potion\n";
        size3 -= 1;
    }
    vector<Treasure> locTreasures = mainChar.getTreasures();
    cout << "\nTreasures:\n";
    std::sort(locTreasures.begin(), locTreasures.end(), compareFunction);
    size3 = locTreasures.size();
    if (size3 == 0)
    {
        cout << "None\n";
    }
    while (size3 - 1 >= 0) {
        cout << locTreasures[size3 - 1].getName() + "\n";
        size3 -= 1;
    }
    cout << "\n---------------------------------------\n";
}


int main()
{
    srand(time(0));

    vector <Location> map;
    Location clearing = Location("Clearing", "There is a warm breeze passing by");
   
    Location temple = Location("Temple", "Vines grow down the walls of a long abandoned temple");
   
    Location house = Location("House", "There is a sweet smell of freshly baked cookies");
    
    Location hall = Location("Hall", "There is a large room filled with seating");
   
    Location library = Location("Library", "Dusty book line the walls");
   
    Location garden = Location("Garden", "Bees float on the slight breeze");
    
    Location forest = Location("Forest", "You can feel eyes peering at you through the darkness");
    
    Location castle = Location("Castle", "Crimson banners hang from the high walls");
    
    Location ruins = Location("Ruins", "Rats scramble around the crumbling ruins");
    
    Location field = Location("Field", "WIld flowers grow in abudance on the vast field");
   
    Location dungeon = Location("Dungeon", "Skeletons lay shackled to the walls, insects roaming the bones");
    
    Location cave = Location("Cave", "Bats fly overhead");

    clearing.addExit({ "W", temple });
    clearing.addExit({ "E", house });
    house.addExit({ "W", clearing });
    house.addExit({ "S", hall });
    house.addExit({ "E", library });
    hall.addExit({ "N", house });
    hall.addExit({ "E", garden });
    garden.addExit({ "W", hall });
    garden.addExit({ "N", library });
    library.addExit({ "W", house });
    library.addExit({ "S", garden });
    temple.addExit({ "S", forest });
    temple.addExit({ "E", clearing });
    forest.addExit({ "N", temple });
    forest.addExit({ "W", field });
    forest.addExit({ "S", castle });
    castle.addExit({ "N", forest });
    castle.addExit({ "W", dungeon });
    castle.addExit({ "S", ruins });
    ruins.addExit({ "N", castle });
    dungeon.addExit({ "N", field });
    dungeon.addExit({ "E", castle });
    field.addExit({ "W", cave });
    field.addExit({ "S", dungeon });
    field.addExit({ "E", forest });
    cave.addExit({ "E", forest });

    Treasure bagOfCoins = Treasure("bag of coins", 50);
    Treasure emerald = Treasure("emerald", 40);
    Treasure sapphire = Treasure("sapphire", 40);
    Treasure diamond = Treasure("diamond", 60);
    Treasure goldRing = Treasure("gold ring", 60);
    Treasure treasureChest = Treasure("treasure chest", 200);
    Treasure ruby = Treasure("ruby", 10);

    Treasure cup = Treasure("cup", 60);
    Treasure pearl = Treasure("pearl", 60);
    Treasure key = Treasure("key", 1);
    Treasure book = Treasure("book", 10);

    Potion redHealing = Potion("red healing", 40);
    Potion blueHealing = Potion("blue healing", 20);
    Potion purpleHealing = Potion("purple healing", 30);

    Weapon dagger = Weapon("dagger", 5);
    Weapon sword = Weapon("sword", 6);
    Weapon stick = Weapon("stick", 1);
    Weapon club = Weapon("club", 3);
    Weapon crossbow = Weapon("crossbow", 10);

    Monster goblin = Monster("goblin", 10);
    Monster zombie = Monster("zombie", 8);
    Monster banshee = Monster("banshee", 7);
    Monster vampire = Monster("vampire", 9);
    Monster orc = Monster("orc", 12);
    Monster spectre = Monster("spectre", 5);
    Monster ghoul = Monster("ghoul", 10);
    Monster dragon = Monster("dragon", 15);
    Monster boss = Monster("boss", 15);

    orc.addItem(cup);
    goblin.addItem(pearl);
    ghoul.addItem(key);
    vampire.addItem(book);

    field.addMonster(goblin);
    dungeon.addMonster(zombie);
    forest.addMonster(banshee);
    castle.addMonster(vampire);
    ruins.addMonster(dragon);
    house.addMonster(orc);
    house.addMonster(spectre);
    garden.addMonster(ghoul);
    cave.addMonster(boss);

    cave.addItem(emerald);
    field.addItem(sapphire);
    field.addItem(dagger);
    dungeon.addItem(redHealing);
    temple.addItem(diamond);
    temple.addItem(sword);
    castle.addItem(goldRing);
    castle.addItem(stick);
    ruins.addItem(purpleHealing);
    clearing.addItem(club);
    house.addItem(treasureChest);
    hall.addItem(bagOfCoins);
    hall.addItem(blueHealing);
    garden.addItem(ruby);
    garden.addItem(crossbow);

    map.push_back(clearing);
    map.push_back(temple);
    map.push_back(house);
    map.push_back(hall);
    map.push_back(library);
    map.push_back(garden);
    map.push_back(forest);
    map.push_back(castle);
    map.push_back(ruins);
    map.push_back(field);
    map.push_back(dungeon);
    map.push_back(cave);

    
    Player mainChar = Player("mainChar",10, 0);
    mainChar.setLocation(clearing.getName());
    Location curr = clearing;
    areaDescription(curr);
    int currIndex = 0;
    bool bossSlain = false;

   

    std::string userInput;

    while (userInput != "quit" && mainChar.getHitPoints() != 0 && bossSlain == false)
    {
        
        cin >> userInput;
        if (userInput == "N" || userInput == "E" || userInput == "S" || userInput == "W")
        {
            vector<pair<std::string, Location>> exits = curr.getExits();
            int size = exits.size();
            while (size - 1 >= 0) {

                if (exits[size - 1].first == userInput)
                {
                    curr = exits[size - 1].second;
                    int size2 = map.size();
                    while (size2 - 1 >= 0) {
                        if (map[size2 - 1].getName() == curr.getName())
                        {
                            curr = map[size2 - 1];
                            currIndex = size2 - 1;
                        }
                        size2 -= 1;
                    }


                }
                size -= 1;

            }
        }
        else if (userInput == "collect")
        {
            mainChar = collectItems(mainChar, curr);
            curr.clearItems();
            map[currIndex] = curr;
        }
        else if (userInput == "drink")
        {
            mainChar.drinkPotions();
        }

        else if (userInput == "inv")
        {
            inventoryDescription(mainChar);

        }

        else if (userInput == "fight")
        {

            vector<Monster> locMonsters = curr.getMonsters();
            int size3 = locMonsters.size();
            if (size3 > 0)
            {
                Monster strongestMonster = locMonsters[size3 - 1];
                while (size3 - 2 >= 0) {
                    if (locMonsters[size3 - 2].getHitPoints() > strongestMonster.getHitPoints())
                    {
                        strongestMonster = locMonsters[size3 - 2];
                    }
                    size3 -= 1;
                }

                mainChar = combat(mainChar, strongestMonster,curr);
                curr.delMonster(strongestMonster);
                vector<Treasure> droppedTreasure = strongestMonster.dropItems();

                int droppedItemSize = droppedTreasure.size();
                while (droppedItemSize - 1 >= 0) {
                    curr.addItem(droppedTreasure[droppedItemSize - 1]);
                    droppedItemSize -= 1;
                }

                if (strongestMonster.getName() == "boss") {

                    bossSlain = true;
                }
                map[currIndex] = curr;
            }

            else 
            {
                cout << "No monsters here";
            }

            
            

        }
        if (mainChar.getHitPoints() != 0)
        {
            areaDescription(curr);
        }
       
        


    }

    cout << "Score:";
    cout << mainChar.getScore();
    cout << "\n\nEnter quit to exit";
    while (userInput != "quit")
    {
        cin >> userInput;
    }


    

    

}

