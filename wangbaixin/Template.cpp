#include <iostream>
#include <string>
using namespace std;
//函数模板  类模板
//这里class等价于typename
//代码膨胀：用模板会生成完全等同于普通函数的函数
template<class T> T Lmax(T a, T b)//传递参数进行 隐式推导类型不同不能推导
{
	return a > b ? a : b;
}
template<class T, class B> T Lmax(T a, B b)//定义两种类型供传递
{
	return a > b ? a : b;
}
template<int x, class T, class B> T Lmax(T a, B b)//可以定义变量，用来计算或传递参数
{
	return a > b ? a : b;
}
void main()
{
	int a = 1, b = 2;
	//显式推导
	cout << sizeof( Lmax<double>(a, b) );
	//隐式推导，若有现成的函数则不用模板推导
	cout << Lmax(a, b);
	//显示模板
	cout << Lmax<>(a, b);
}