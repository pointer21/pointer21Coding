#include "rand.h"


int _rand::getRand(int a)//rand����[0,a)����
{
	return  rand() % a;
}
int _rand::getRand(int a, int b)//rand����[a,b)����
{
	return  rand() % (b - a) + a;
}
double _rand::Doubleprobability()//����һ��0~1�����С��double
{
	return ((double)rand()) / RAND_MAX;
}
double _rand::Doubleprobability(int a, int b)//����a~b�����С��
{
	double d = ((double)rand()) / RAND_MAX;
	return rand() % (b - a) + d;
}
bool _rand::JudgeInteger(int pro)//����0��100���������������жϳɹ�,�ɹ�����true
{
	int s = 0;
	for (int i = 0; i < 100; i++)
	{
		int r = rand() % 100;
		if (r<pro)
		{
			s++;
		}
	}
	std::cout << s << std::endl;//����
	return true;
}
bool _rand::JudgeInteger(double pro)//����0��1��double���������жϳɹ����ɹ�����ture��
{
	int s = 0;
	for (int i = 0; i < 100; i++)
	{
		int r = rand() % 100;
		if (r < pro * 100)
		{
			s++;
		}
	}
	std::cout << s << std::endl;//����
	return true;
}