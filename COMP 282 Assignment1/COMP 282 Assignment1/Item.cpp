#include "Item.h"
#include <iostream>
using namespace std;
using namespace itm;

void Item::setName(std::string newName)
{
	name = newName;
}

std::string Item::getName()
{
	return name;
}

void Weapon::setPower(int newPower)
{
	power = newPower;
}

int Weapon::getPower()
{
	return power;
}

void Potion::setStrength(int newStrength)
{
	strength = newStrength;
}

int Potion::getStrength()
{
	return strength;
}

void Treasure::setValue(int newValue)
{
	value = newValue;
}

int Treasure::getValue()
{
	return value;
}