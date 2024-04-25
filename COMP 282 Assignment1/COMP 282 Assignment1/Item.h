#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#ifndef ITEM_H
#define ITEM_H
namespace itm {
    class Item {
    protected:
        std::string name;
    public:
        Item(std::string itemName) : name(itemName) {}
        void setName(std::string newName);
        std::string getName();
    };

    class Potion : public Item {
    protected:
        int strength;
    public:
        Potion(std::string itemName, int potionStrength) : Item(itemName), strength(potionStrength) {}
        void setStrength(int newStrength);
        int getStrength();

    };

    class Weapon : public Item {
    protected:
        int power;
    public:
        Weapon(std::string itemName, int weaponPower) : Item(itemName), power(weaponPower) {}
        void setPower(int newPower);
        int getPower();

    };

    class Treasure : public Item {
    protected:
        int value;
    public:
        Treasure(std::string itemName, int treasureValue) : Item(itemName), value(treasureValue) {}
        void setValue(int newValue);
        int getValue();

    };

}
#endif#
