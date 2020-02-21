#include<iostream>
#include"weapon.h"
#include<string>
using namespace std;

weapon::weapon(string n,int atk)
{
	name = n;
	attack = atk;
}
weapon::~weapon()
{

}
