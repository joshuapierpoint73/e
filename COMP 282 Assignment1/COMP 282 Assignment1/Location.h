#pragma once
#ifndef LOCATION_H
#define LOCATION_H

#include "Character.h"
#include <iostream>
#include "Item.h"
#include <vector>

using namespace std;
using namespace ch;
using namespace itm;

namespace loc {
	class Location {
	protected:
		std::string name;
		std::string description;
		vector<pair<std::string,Location>> exits;
		vector<Monster> monsters;
		vector<Potion> potions;
		vector<Weapon> weapons;
		vector<Treasure> treasures;
	public:
		Location(std::string locationName, std::string locationDesc) : name(locationName), description(locationDesc) {}
		void setName(std::string newName);
		std::string getName();
		void setDescription(std::string newDescription);
		std::string getDescription();
		void addExit(pair<std::string,Location> exit);
		vector<pair<std::string,Location>> getExits();
		void addMonster(Monster newMonster);
		void delMonster(Monster newMonster);
		vector<Monster> getMonsters();
		void addItem(Potion newItem);
		void addItem(Treasure newItem);
		void addItem(Weapon newItem);
		vector<Potion> getPotions();
		vector<Treasure> getTreasures();
		vector<Weapon> getWeapons();
		void clearItems();
	};
}
#endif#
