#pragma once


#ifndef CHARACTER_H
#define CHARACTER_H

#include "Item.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;
using namespace itm;

namespace ch {
    class Character {
    protected:
        int hitpoints;
        std::string name;
    public:
        Character(std::string charName,int hp) : hitpoints(hp), name(charName) {}
        void setHitPoints(int hp);
        int getHitPoints();
        void setName(std::string newName);
        std::string getName();
        void takeHit(int damage);
    };

    class Monster : public Character {
    protected:
        vector <Treasure> items;
    public:
        Monster(std::string charName, int hp) : Character(charName,hp){}
        vector<Treasure> dropItems();
        void addItem(Treasure newItem);
    };

    class Player : public Character {
    protected:
        int score;
        vector <Potion> potions;
        vector <Weapon> weapons;
        vector <Treasure> treasures;
        std::string location;
    public:
        Player(std::string charName, int hp, int baseScore) : Character(charName,hp), score(baseScore) {}
        void setScore(int newScore);
        int getScore();
        void setLocation(std::string newLocation);
        std::string getLocation();
        void addItem(Potion newItem);
        void addItem(Treasure newItem);
        void addItem(Weapon newItem);
        vector<Potion> getPotions();
        vector<Treasure> getTreasures();
        vector<Weapon> getWeapons();
        void drinkPotions();
        

    };
}
#endif#
