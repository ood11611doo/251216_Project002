#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

Player::Player(string _nickname)
{
	nickname = _nickname;
	level = 1;
	health = 100;
	mana = 0;
	power = 10;
	defence = 5;
	accuracy = 80;
	speed = 10;
}

void Player::printPlayerStatus(bool isOpened, string& status)
{
	string outputs = "";
	if (!isOpened)
	{
		outputs += "[p]스탯 보기------------------------\n";
		status = outputs;
		return;
	}

	outputs += "[p]스탯 숨기기----------------------\n";
	outputs += "* 현재 능력치\n";
	outputs += "닉네임: " + nickname + "\n";
	outputs += "직업: " + job_name + "\n";
	outputs += "Lv. " + to_string(level) + "\n";
	outputs += "HP: " + to_string(health) + "\n";
	outputs += "MP: " + to_string(mana) + "\n";
	outputs += "공격력: " + to_string(power) + "\n";
	outputs += "방어력: " + to_string(defence) + "\n";
	outputs += "정확도: " + to_string(accuracy) + "\n";
	outputs += "속도: " + to_string(speed) + "\n";
	outputs += "------------------------------------\n";
	status = outputs;
}

string Player::getJobName()
{
	return job_name;
}
string Player::getNickname()
{
	return nickname;
}
int Player::getLevel()
{
	return level;
}
int Player::getHP()
{
	return health;
}
int Player::getMP()
{
	return mana;
}
int Player::getPower()
{
	return power;
}
int Player::getDefence()
{
	return defence;
}
int Player::getAccuracy()
{
	return accuracy;
}
int Player::getSpeed()
{
	return speed;
}

void Player::setNickname(string _nickname)
{
	nickname = _nickname;
}
bool Player::setHP(int _health)
{
	if (_health <= 0)
	{
		health = 0;
		return false;
	}
	health = _health;
	return true;
}
bool Player::setMP(int _mana)
{
	if (_mana <= 0)
	{
		mana = 0;
		return false;
	}
	mana = _mana;
	return true;
}
void Player::setPower(int _power)
{
	power = _power;
}
void Player::setDefence(int _defence)
{
	defence = _defence;
}
void Player::setAccuracy(int _accuracy)
{
	accuracy = _accuracy;
}
void Player::setSpeed(int _speed)
{
	speed = _speed;
}