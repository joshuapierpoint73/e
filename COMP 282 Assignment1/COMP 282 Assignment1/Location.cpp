#include "Location.h"
#include <iostream>
using namespace std;
using namespace loc;

void Location::setName(std::string newName)
{
	name = newName;
}

std::string Location::getName()
{
	return name;
}

void Location::setDescription(std::string newDesc)
{
	description = newDesc;
}

std::string Location::getDescription()
{
	return description;
}

void Location::addExit(pair<std::string,Location> newExit)
{
	exits.push_back(newExit);

}

vector<pair<std::string,Location>> Location::getExits()
{
	return exits;
}

void Location::addMonster(Monster newMonster)
{
	monsters.push_back(newMonster);
}

void Location::delMonster(Monster newMonster)
{
	int size = monsters.size();
	while (size - 1 >= 0) {

		if (monsters[size - 1].getName() == newMonster.getName())
		{
			monsters.erase(monsters.begin() + (size - 1));
		}
		size -= 1;

	}
	
}

void Location::addItem(Potion newPotion)
{
	potions.push_back(newPotion);
}

void Location::addItem(Weapon newWeapon)
{
	weapons.push_back(newWeapon);
}

void Location::addItem(Treasure newTreasure)
{
	treasures.push_back(newTreasure);
}

vector<Potion> Location::getPotions()
{
	return potions;
}

vector<Weapon> Location::getWeapons()
{
	return weapons;
}

vector<Treasure> Location::getTreasures()
{
	return treasures;
}

vector<Monster> Location::getMonsters()
{
	return monsters;
}

void Location::clearItems()
{
	treasures.clear();
	potions.clear();
	weapons.clear();
}