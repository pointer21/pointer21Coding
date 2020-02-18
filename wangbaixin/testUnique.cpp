#include "templat.h"
#include <iostream>
#include <string>
#include <memory>
using namespace std;
class tool{

public:
	int value = 0;
	tool()
	{
		cout << "构造函数" << endl;
	}
	~tool()
	{
		cout << "~析构函数" << endl;
	}
};

void runUnique()
{
	unique_PTR<tool> ptr1{ new tool };
	//unique_PTR<tool> ptr2(ptr1);//不允许拷贝
	cout << ptr1->value << endl;
	cout << ptr1.get() << endl;
}
void main1()
{
	shared_ptr<tool> ptr{ new tool };
	weak_ptr<tool> wptr(ptr);
	//runUnique();
}