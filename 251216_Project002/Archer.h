#pragma once
#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

class Archer : public Player
{
public:
	Archer(string _nickname);
	bool attack() override;
	bool attack(Monster* monster, string& debugs) override;
};