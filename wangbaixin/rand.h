#include <iostream>
#include <string>

class _rand{
public:
	int getRand(int a);//����[0,a)����
	int getRand(int a, int b);//rand����[a,b)����
	double Doubleprobability();//����һ��0~1�����С��double
	double Doubleprobability(int a, int b);//����a~b�����С��
	bool JudgeInteger(int n);//����0��100���������������жϳɹ�,�ɹ�����true
	bool JudgeInteger(double pro);//����0��1��double���������жϳɹ����ɹ�����ture��
};