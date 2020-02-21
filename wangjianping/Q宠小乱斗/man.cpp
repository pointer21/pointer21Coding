#include<iostream>
#include<string>
#include"weapon.h"
#include"man.h"
using namespace std;
man::man(string n,int a)
{
	name = n;
}
man::~man()
{

}
void man::addwepon(weapon* w)
{
	cout << name << "使用了" << w->name << endl;
	atk = w->attack;
}
int man::blood()
{
	
	cout << "[ "<<name<<" ]" <<hp<< "受到了" << atk << "点攻击" << endl;
	hp -= atk;
	return hp ;
}