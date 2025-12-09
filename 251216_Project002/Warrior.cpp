#include <iostream>
#include <string>
#include "Warrior.h"

using namespace std;

Warrior::Warrior(string _nickname) : Player(_nickname)
{
	job_name = "전사";
	health = 150;
	power = 15;
	defence = 8;
	accuracy = 75;
	speed = 8;
}

bool Warrior::attack()
{
	cout << "* 전사의 공격은 강력한 단일 공격입니다." << endl;
	return false;
}
bool Warrior::attack(Monster* monster, string& debugs)
{
	string outputs = "\n";
	int damage = power - monster->getDefence();
	if (damage <= 0)
	{
		damage = 1;
	}
	int new_health = monster->getHP() - damage;
	bool hpCheck = monster->setHP(new_health);
	outputs += "* 전사 " + nickname + "의 " + to_string(damage) + "데미지 공격!\n";
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