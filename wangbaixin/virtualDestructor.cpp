#include <iostream>
#include <string>
using namespace std;

class people
{
public:
	people()
	{
		cout << "构造函数people" << endl;
	}
	virtual void dowork()
	{
		cout << "父类dowork" << endl;
	}
	virtual~people()
	{
		cout << "析构~people" << endl;
	}
};

class worker :public people
{
public:
	worker()
	{
		cout << "构造函数worker" << endl;
	}
	void dowork()
	{
		cout << "子类dowork" << endl;
	}
	void wash()
	{
		cout << "洗浴" << endl;
	}
	 ~worker()
	{
		cout << "析构~worker" << endl;
	}
};
class tool :public worker
{
public:
	tool()
	{
		cout << "构造函数tool" << endl;
	}
	void dowork()
	{
		cout << "tool" << endl;
	}
	~tool()
	{
		cout << "析构~tool" << endl;
	}
};
void main()
{
	
	//实现虚析构。实现 隐藏。

	//1.函数隐藏：
	tool *t = new tool;
	t->dowork();//调用派生类函数，将父类隐藏

	cout << endl;
	//2.实现虚析构
	worker *w = new tool;
	delete w;
	cout << endl;
	people *p = new worker;
	delete p;//析构时只会析构父类的，而不会析构子类tool，导致内存泄漏，为了解决内存泄漏引入虚析构
	
}