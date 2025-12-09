#pragma once
#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

class Thief : public Player
{
public:
	Thief(string _nickname);
	bool attack() override;
	bool attack(Monster* monster, string& debugs) override;
};