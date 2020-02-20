#include "rand.h"


int _rand::getRand(int a)//rand生成[0,a)的数
{
	return  rand() % a;
}
int _rand::getRand(int a, int b)//rand生成[a,b)的数
{
	return  rand() % (b - a) + a;
}
double _rand::Doubleprobability()//生成一个0~1的随机小数double
{
	return ((double)rand()) / RAND_MAX;
}
double _rand::Doubleprobability(int a, int b)//生成a~b的随机小数
{
	double d = ((double)rand()) / RAND_MAX;
	return rand() % (b - a) + d;
}
bool _rand::JudgeInteger(int pro)//传入0到100的整数，概率性判断成功,成功返回true
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
	std::cout << s << std::endl;//概率
	return true;
}
bool _rand::JudgeInteger(double pro)//传入0到1的double，概率性判断成功，成功返回ture。
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
	std::cout << s << std::endl;//概率
	return true;
}