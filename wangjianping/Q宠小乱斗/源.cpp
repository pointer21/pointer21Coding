#include<iostream>
#include<string>
#include<Windows.h>
#include<math.h>
#include<time.h>
#include"man.h"
#include"weapon.h"

void winner(man* n)
{
	cout <<n->name << "��ʤ��" << endl;
}

void randrun1(man* man1)
{
	
	int p = rand()% 3;
	if (p == 0)
	{
		weapon* weapon1 = new weapon("���°�", 20);
		man1->addwepon(weapon1);
		return;
	}
	if (p==1)
	{
		weapon* weapon1 = new weapon("����", 15);
		man1->addwepon(weapon1);
		return;
	}
	else
	{
		weapon* weapon1 = new weapon("����", 25);
		man1->addwepon(weapon1);
		return;
	}
}
void randrun2(man* man2)
{
	int p = rand() %3;
	if (p == 0)
	{
		weapon* weapon2 = new weapon("������", 20);
		man2->addwepon(weapon2);
		return;
	}
	if (p == 1)
	{
		weapon* weapon2 = new weapon("�Բ���", 15);
		man2->addwepon(weapon2);
		return;
	}
	else
	{
		weapon* weapon2 = new weapon("������", 25);
		man2->addwepon(weapon2);
		return;
	}
}
int main()
{
	srand(time(0));
	man* man1 = new man("��С��",10);
	man* man2 = new man("��Сƽ",10);
	while (1)
	{
		randrun1(man1);
		randrun2(man2);
		if (man1->hp<=0)
		{
			winner(man2);
			break;
		}
		if (man2->hp<=0)
		{
			winner(man1);
			break;
		}
		else
		{
			man1->blood();
			man2->blood();
		}
	}


	return 0;
}
