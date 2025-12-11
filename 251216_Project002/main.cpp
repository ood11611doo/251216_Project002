// Copyright (c) 2025 by ood11611doo. All rights reserved.

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_RAND_S

#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include "Player.h"
#include "Monster.h"
#include "Archer.h"
#include "Magician.h"
#include "Thief.h"
#include "Warrior.h"

using namespace std; // NOLINT

enum CurrentMenu {
  mainMenu,
  inBattle,
  battleEnd,
  dead,
  exitCommand
};

// used on menu text input
string menuItems() {
  string outputs = "";
  outputs += "1. 전투 시작\n";
  outputs += "esc. 종료\n";
  return outputs;
}

// used on thread
void battleTask(CurrentMenu& menuStats, Player& plGet, string& battleMsg) {
  menuStats = CurrentMenu::inBattle;
  string randNames[] = { "슬라임", "고블린", "오크", "트롤", "스켈레톤" };
  unsigned int randIndex;
  rand_s(&randIndex);
  int randFound = randIndex % 5;
  Monster monster(randNames[randFound]);

  battleMsg = "* 몬스터 " + monster.getName() + "(이)가 등장했다!\n";

  int plSpeed = plGet.getSpeed();
  int monSpeed = monster.getSpeed();
  bool plCheck = false, monCheck = false;
  while (!plCheck && !monCheck) {
    if (plSpeed >= monSpeed) {
      plSpeed -= monSpeed;
      monSpeed = monster.getSpeed();
      monCheck = plGet.attack(&monster, battleMsg);
    } else {
      monSpeed -= plSpeed;
      plSpeed = plGet.getSpeed();
      plCheck = monster.attack(&plGet, battleMsg);
    }

    this_thread::sleep_for(chrono::milliseconds(750));
  }

  battleMsg += "\n";
  battleMsg += "* 전투가 종료되었습니다!\n";
  battleMsg += "1. 메뉴로 돌아가기\n";
  menuStats = CurrentMenu::battleEnd;
}

int main() {
  // Move cursor to home position
  const string ANSI_CURSOR_HOME = "\033[H";
  // Clear screen from cursor down
  const string ANSI_CLEAR_SCREEN = "\033[J";
  // Hide the cursor
  const string ANSI_CURSOR_HIDE = "\033[?25l";
  // Show the cursor
  const string ANSI_CURSOR_SHOW = "\033[?25h";

  string statusMsg;
  string menuMsg;
  string battleMsg;



  bool statToggle = true;
  CurrentMenu currentMenu = mainMenu;

  string jobs[] = { "전사", "마법사", "도적", "궁수" };
  int job_choice = 0;
  string nickname;

  Player* player = nullptr;

  cout << "* 닉네임을 입력해주세요: ";
  cin >> nickname;

  cout << "<전직 시스템>" << endl;
  cout << nickname << "님, 환영합니다!" << endl;
  cout << "* 원하시는 직업을 선택해주세요." << endl;
  for (int i = 0; i < 4; i++) {
    cout << (i + 1) << ". " << jobs[i] << endl;
  }

  cout << "선택: ";
  cin >> job_choice;

  while (job_choice < 1 || job_choice > 4) {
    cout << "잘못된 입력입니다. 다시 선택해주세요: ";
    cin >> job_choice;
  }
  switch (job_choice) {
    case 1:
      player = new Warrior(nickname);
      break;
    case 2:
      player = new Magician(nickname);
      break;
    case 3:
      player = new Thief(nickname);
      break;
    case 4:
      player = new Archer(nickname);
      break;
    default:
      cout << "잘못된 입력입니다." << endl;
      return 1;
  }

  player->attack();

  this_thread::sleep_for(chrono::seconds(2));
  system("cls");

  cout << ANSI_CURSOR_HIDE << flush;

  menuMsg = menuItems();

  while (currentMenu != CurrentMenu::dead &&
    currentMenu != CurrentMenu::exitCommand) {
    cout << ANSI_CURSOR_HOME;
    cout << ANSI_CLEAR_SCREEN;

    if (_kbhit()) {
      char keyIn = _getch();

      if (keyIn == 'p' || keyIn == 'P') {
        statToggle = !statToggle;
      }

      switch (currentMenu) {
        case mainMenu:
          if (keyIn == 27) {
            currentMenu = CurrentMenu::exitCommand;
          } else if (keyIn == '1') {
            battleMsg = "";
            thread battleThread(battleTask,
              ref(currentMenu), ref(*player), ref(battleMsg));
            battleThread.detach();
          }
          break;
        case inBattle:
          break;
        case battleEnd:
          if (keyIn == '1') {
            if (player->getHP() <= 0) {
              currentMenu = CurrentMenu::dead;
              break;
            }
            currentMenu = CurrentMenu::mainMenu;
          }
          break;
        default:
          break;
      }
    }

    if (currentMenu == CurrentMenu::mainMenu) {
      player->attack();
    }
    player->printPlayerStatus(statToggle, statusMsg);
    cout << statusMsg;

    switch (currentMenu) {
      case mainMenu:
        cout << menuMsg;
        break;
      case inBattle:
        cout << battleMsg;
        break;
      case battleEnd:
        cout << battleMsg;
        break;
      default:
        break;
    }

    cout.flush();

    this_thread::sleep_for(chrono::milliseconds(100));
  }

  if (currentMenu == CurrentMenu::dead) {
    cout << "* 플레이어 " + player->getNickname() +
      "가(이) 사망했습니다. 게임을 종료합니다." << endl;
  } else {
    cout << "* 게임이 종료되었습니다." << endl;
  }

  cout << ANSI_CURSOR_SHOW << flush;

  if (player != nullptr) {
    delete player;
  }
  return 0;
}
