// Copyright (c) 2025 by ood11611doo. All rights reserved.

#pragma once
#include <iostream>
#include <string>
#include "Player.h"

using namespace std; // NOLINT

class Thief : public Player {
 public:
  explicit Thief(string _nickname);
  bool attack() override;
  bool attack(Monster* monster, string& debugs) override;
};
