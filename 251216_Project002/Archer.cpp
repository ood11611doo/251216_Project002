// Copyright (c) 2025 by ood11611doo. All rights reserved.

#include <cmath>
#include <iostream>
#include <string>
#include "Archer.h"

using namespace std; // NOLINT

Archer::Archer(string _nickname) : Player(_nickname) {
  job_name = "궁수";
  health = 90;
  power = 15;
  defence = 2;
  accuracy = 95;
  speed = 15;
}

bool Archer::attack() {
  cout << "* 궁수의 공격은 데미지/3 의 방식으로 3번 연속 공격합니다." << endl;
  return false;
}
bool Archer::attack(Monster* monster, string& debugs) {
  string outputs = "\n";
  for (int i = 0; i < 3; ++i) {
    int base_damage = floor(static_cast<float>(power) / 3);
    if (base_damage <= 0) {
      base_damage = 1;
    }
    int damage = base_damage - monster->getDefence();
    if (damage <= 0) {
      damage = 1;
    }
    int new_health = monster->getHP() - damage;
    bool hpCheck = monster->setHP(new_health);
    outputs += "* 궁수 " + nickname + "의 " +
      to_string(damage) + "데미지 공격!\n";
    outputs += "* 몬스터 " + monster->getName() +
      "의 남은 체력: " + to_string(monster->getHP()) + "\n";
    if (!hpCheck) {
      outputs += "\n";
      outputs += "* 몬스터 " + monster->getName() + "가(이) 사망했습니다!\n";
      outputs += "* 플레이어 " + nickname + "의 승리!\n";
      debugs += outputs;
      return true;
    } else {
      outputs += "\n";
    }
  }
  debugs += outputs;
  return false;
}
