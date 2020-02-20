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
	cout << r.getRand(3) << endl;//1.rand生成[0,a)的数
	cout << r.getRand(3, 10) << endl;//rand生成[a,b)的数
	cout << r.Doubleprobability()<<endl;//生成一个0~1的随机小数double
	cout << r.Doubleprobability(3, 10) << endl;//生成a~b的随机小数
	r.JudgeInteger(0.1);
	r.JudgeInteger(80);
}