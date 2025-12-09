#include <iostream>
#include <string>
#include "Player.h"
#include "Monster.h"

using namespace std;

Monster::Monster(string _name)
{
	name = _name;
	health = 10;
	power = 30;
	defence = 10;
	speed = 10;
}

bool Monster::attack(Player* pl, string& debugs)
{
	string outputs = "\n";
	int damage = power - pl->getDefence();
	if (damage <= 0)
		damage = 1;
	int new_health = pl->getHP() - damage;
	bool hpCheck = pl->setHP(new_health);
	outputs += "* 몬스터 " + name + "의 " + to_string(damage) + "데미지 공격!\n";
	outputs += "* 플레이어 " + pl->getNickname() + "의 남은 체력: " + to_string(pl->getHP()) + "\n";
	if (!hpCheck)
	{
		outputs += "\n";
		outputs += "* 플레이어 " + pl->getNickname() + "가(이) 사망했습니다!\n";
		outputs += "* 몬스터 " + name + "의 승리!\n";
		debugs += outputs;
		return true;
	}
	debugs += outputs;
	return false;
}

string Monster::getName()
{
	return name;
}
int Monster::getHP()
{
	return health;
}
int Monster::getPower()
{
	return power;
}
int Monster::getDefence()
{
	return defence;
}
int Monster::getSpeed()
{
	return speed;
}

void Monster::setName(string _name)
{
	name = _name;
}
bool Monster::setHP(int _health)
{
	if (_health <= 0)
	{
		health = 0;
		return false;
	}
	health = _health;
	return true;
}
void Monster::setPower(int _power)
{
	power = _power;
}
void Monster::setDefence(int _defence)
{
	defence = _defence;
}
void Monster::setSpeed(int _speed)
{
	speed = _speed;
}