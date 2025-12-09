#include <iostream>
#include <string>
#include <cmath>
#include "Thief.h"

using namespace std;

Thief::Thief(string _nickname) : Player(_nickname)
{
	job_name = "도적";
	health = 80;
	power = 10;
	defence = 4;
	accuracy = 90;
	speed = 20;
}

bool Thief::attack()
{
	cout << "* 도적의 공격은 데미지/5 의 방식으로 5번 연속 공격합니다." << endl;
	return false;
}
bool Thief::attack(Monster* monster, string& debugs)
{
	string outputs = "\n";
	for (int i = 0; i < 5; ++i)
	{
		int base_damage = floor((float)power / 5);
		if (base_damage <= 0)
		{
			base_damage = 1;
		}
		int damage = base_damage - monster->getDefence();
		if (damage <= 0)
		{
			damage = 1;
		}
		int new_health = monster->getHP() - damage;
		bool hpCheck = monster->setHP(new_health);
		outputs += "* 도적 " + nickname + "의 " + to_string(damage) + "데미지 공격!\n";
		outputs += "* 몬스터 " + monster->getName() + "의 남은 체력: " + to_string(monster->getHP()) + "\n";
		if (!hpCheck)
		{
			outputs += "\n";
			outputs += "* 몬스터 " + monster->getName() + "가(이) 사망했습니다!\n";
			outputs += "* 플레이어 " + nickname + "의 승리!\n";
			debugs += outputs;
			return true;
		}
		else
		{
			outputs += "\n";
		}
	}
	debugs += outputs;
	return false;
}