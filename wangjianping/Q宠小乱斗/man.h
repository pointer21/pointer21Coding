#pragma once
#include<string>
class weapon;
using namespace std;

class man
{
public:
	int hp = 100;
	int atk = 10;
	string name = "Ĭ������";
	man(string n, int a);
	~man();
	void addwepon(weapon* w);
	int blood();
};