#pragma once
#include<string>
#include"man.h"
using namespace std;

class weapon
{
public:
	string name="Ä¬ÈÏÎäÆ÷";
	int attack = 1;
	weapon(string n,int atk);
	virtual~weapon();
};
