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
	
};

class worker:public people
{
public:
	worker()
	{
		cout << "构造函数worker" << endl;
	}
	virtual void dowork()
	{
		cout << "子类dowork" << endl;
	}
	
};
class tool:public worker
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
};
void main2()
{
	//实现子类对象父类指针实现多态效果
	worker *w = new tool;//父类指针  子类对象
	
	w->dowork();
}