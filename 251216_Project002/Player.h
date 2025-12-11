// Copyright (c) 2025 by ood11611doo. All rights reserved.

#pragma once
#include <iostream>
#include <string>
#include "Monster.h"

using namespace std; // NOLINT

class Player {
 public:
  explicit Player(string _nickname);
  virtual bool attack() = 0;
  virtual bool attack(Monster* monster, string& debugs) = 0;
  void printPlayerStatus(bool isOpened, string& status);

  string getJobName();
  string getNickname();
  int getLevel();
  int getHP();
  int getMP();
  int getPower();
  int getDefence();
  int getAccuracy();
  int getSpeed();

  void setNickname(string nickname);
  bool setHP(int _health);
  bool setMP(int _mana);
  void setPower(int _power);
  void setDefence(int _defence);
  void setAccuracy(int _accuracy);
  void setSpeed(int _speed);

 protected:
  string job_name;
  string nickname;
  int level;
  int health;
  int mana;
  int power;
  int defence;
  int accuracy;
  int speed;
};
