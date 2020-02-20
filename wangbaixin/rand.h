#include <iostream>
#include <string>

class _rand{
public:
	int getRand(int a);//生成[0,a)的数
	int getRand(int a, int b);//rand生成[a,b)的数
	double Doubleprobability();//生成一个0~1的随机小数double
	double Doubleprobability(int a, int b);//生成a~b的随机小数
	bool JudgeInteger(int n);//传入0到100的整数，概率性判断成功,成功返回true
	bool JudgeInteger(double pro);//传入0到1的double，概率性判断成功，成功返回ture。
};