#pragma once
#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

class Magician : public Player
{
public:
	Magician(string _nickname);
	bool attack() override;
	bool attack(Monster* monster, string& debugs) override;
};