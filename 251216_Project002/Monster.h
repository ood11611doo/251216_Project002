// Copyright (c) 2025 by ood11611doo. All rights reserved.

#pragma once
#include <iostream>
#include <string>

using namespace std; // NOLINT

class Player;  // Forward declaration

class Monster {
 public:
  explicit Monster(string _name);
  bool attack(Player* pl, string& debugs);

  string getName();
  int getHP();
  int getPower();
  int getDefence();
  int getSpeed();

  void setName(string _name);
  bool setHP(int _health);
  void setPower(int _power);
  void setDefence(int _defence);
  void setSpeed(int _speed);

 protected:
  string name;
  int health;
  int power;
  int defence;
  int speed;
};
