#pragma once
#include<string>
class weapon;
using namespace std;

class man
{
public:
	int hp = 100;
	int atk = 10;
	string name = "Ä¬ÈÏÃû×Ö";
	man(string n, int a);
	~man();
	void addwepon(weapon* w);
	int blood();
};