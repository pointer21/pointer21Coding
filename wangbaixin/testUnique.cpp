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
		cout << "���캯��" << endl;
	}
	~tool()
	{
		cout << "~��������" << endl;
	}
};

void runUnique()
{
	unique_PTR<tool> ptr1{ new tool };
	//unique_PTR<tool> ptr2(ptr1);//��������
	cout << ptr1->value << endl;
	cout << ptr1.get() << endl;
}
void main1()
{
	shared_ptr<tool> ptr{ new tool };
	weak_ptr<tool> wptr(ptr);
	//runUnique();
}