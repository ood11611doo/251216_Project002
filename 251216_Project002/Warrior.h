#pragma once
#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

class Warrior : public Player
{
public:
	Warrior(string _nickname);
	bool attack() override;
	bool attack(Monster* monster, string& debugs) override;
};