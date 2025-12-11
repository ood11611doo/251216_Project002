// Copyright (c) 2025 by ood11611doo. All rights reserved.

#pragma once
#include <iostream>
#include <string>
#include "Player.h"

using namespace std; // NOLINT

class Warrior : public Player {
 public:
  explicit Warrior(string _nickname);
  bool attack() override;
  bool attack(Monster* monster, string& debugs) override;
};
