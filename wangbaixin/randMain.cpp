#include <iostream>
#include <string>
#include <time.h>
#include "rand.h"
#include <windows.h>
using namespace std;


void main()
{
	_rand r;
	srand(time(0));
	cout << r.getRand(3) << endl;//1.rand����[0,a)����
	cout << r.getRand(3, 10) << endl;//rand����[a,b)����
	cout << r.Doubleprobability()<<endl;//����һ��0~1�����С��double
	cout << r.Doubleprobability(3, 10) << endl;//����a~b�����С��
	r.JudgeInteger(0.1);
	r.JudgeInteger(80);
}