#include "Item.h"
#include "Character.h"
#include <iostream>
#include <vector>
using namespace std;
using namespace ch;
using namespace itm;


void Character::setHitPoints(int hp)
{
	hitpoints = hp;
}

int Character::getHitPoints()
{
	return hitpoints;
}

void Character::setName(std::string newName)
{
	name = newName;
}

std::string Character::getName()
{
	return name;
}

void Player::setScore(int newScore)
{
	score = newScore;
}

int Player::getScore()
{
	return score;
}

void Player::setLocation(std::string newLocation)
{
	location = newLocation;
}

std::string Player::getLocation()
{
	return location;
}

void Player::addItem(Potion newPotion)
{
	potions.push_back(newPotion);
}

void Monster::addItem(Treasure newItem)
{
	items.push_back(newItem);
}

void Player::addItem(Weapon newWeapon)
{
	weapons.push_back(newWeapon);
}

void Player::addItem(Treasure newTreasure)
{
	treasures.push_back(newTreasure);
}

vector<Potion> Player::getPotions()
{
	return potions;
}

vector<Weapon> Player::getWeapons()
{
	return weapons;
}

vector<Treasure> Player::getTreasures()
{
	return treasures;
}

void Character::takeHit(int damage)
{
	hitpoints -= damage;
	if (hitpoints < 0)
	{
		hitpoints = 0;
	}
}

vector<Treasure> Monster::dropItems()
{
	return items;
}


void Player::drinkPotions()
{
	int size3 = potions.size();
	while (size3 - 1 >= 0) {
		hitpoints += potions[size3 - 1].getStrength();
		size3 -= 1;
	}
	potions.clear();
}