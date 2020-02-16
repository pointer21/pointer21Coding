#include<iostream>
#include<vector>
#include<string>
#include<assert.h>
#include<Initializer_List>
using namespace std;

template<class T> T lmax(T a,T b)
{
	return a > b ? a : b;
}
//A lmax(A a,A b)
//{
//	return a.operator > (b) ? a : b;
//}
//class A
//{
//public:
//	bool operator>(A&)
//	{
//		return true;
//	}
//};
//ostream& operator<<(ostream& o,A& a)
//{
//	cout << "cout输出了A类型的" << endl;
//	return o;
//}


//swap
template<class T> void lswap(T& a, T& b)
{
	T tem = a;
	a = b;
	b = tem;
}
class A
{
public:
	int value = 0;
	char* p;
	A(int v)
	{
		p = new char[100];
		value = v;
		cout << "构造" << endl;
	}
	A(const A& other)
	{
		p = new char[200];
		value = other.value;
		cout << "拷贝" << endl;

	}
	~A()
	{
		delete p;
	}
};
int main2()
{
	int x1 = 2, x2 = 5;
	double d1 = 2, d2 = 4.4;
	//隐式推导
	cout << lmax(x1, x2) << endl;
	//显示推导
	cout << lmax<double>(d1, d2) << endl; 
	//显示指定模板
	cout << lmax<>(d1, d2) << endl;
	lswap(x1,x2);
	cout << x2 << "交换为" << x1 << endl;
	return 0;

}




