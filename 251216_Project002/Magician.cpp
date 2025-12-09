#include <iostream>
#include <string>
#include <cmath>
#include "Magician.h"

using namespace std;

Magician::Magician(string _nickname) : Player(_nickname)
{
	job_name = "마법사";
	health = 70;
	mana = 150;
	power = 10;
	defence = 0;
	accuracy = 85;
	speed = 10;
}

bool Magician::attack()
{
	cout << "* 마법사의 공격은 마나가 있을 시 마나를 일정 소모해 2배의 데미지를, 마나가 없을 시 0.5배의 데미지를 줍니다." << endl;
	return false;
}
bool Magician::attack(Monster* monster, string& debugs)
{
	string outputs = "\n";
	int damage;
	if (mana >= 30)
	{
		damage = (power * 2) - monster->getDefence();
		mana -= 30;
	}
	else
	{
		damage = floor(power / 2) - monster->getDefence();
	}
	if (damage <= 0)
	{
		damage = 1;
	}
	int new_health = monster->getHP() - damage;
	bool hpCheck = monster->setHP(new_health);
	outputs += "* 마법사 " + nickname + "의 " + to_string(damage) + "데미지 공격!\n";
	outputs += "* 몬스터 " + monster->getName() + "의 남은 체력: " + to_string(monster->getHP()) + "\n";
	if (!hpCheck)
	{
		outputs += "\n";
		outputs += "* 몬스터 " + monster->getName() + "가(이) 사망했습니다!\n";
		outputs += "* 플레이어 " + nickname + "의 승리!\n";
		debugs += outputs;
		return true;
	}
	debugs += outputs;
	return false;
}