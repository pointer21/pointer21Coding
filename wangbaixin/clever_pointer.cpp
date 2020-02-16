#include <iostream>
#include <string>
#include "clever.h"
using namespace std;
class tool
{
	char *p = new char[12];
public:
	int value = 0;
	tool(){ cout << "构造了" << endl; }
	~tool(){ cout << "析构了" << endl; }
};
void main()
{
	//auto_ptr<tool> ptr{ new tool };
	//auto_ptr<tool> ptr2(ptr);
	//auto_ptr<tool> ptr3;
	//ptr3 = ptr2;
	r_autoPtr<tool> ptr1(new tool);
	r_autoPtr<tool> ptr2(ptr1);
	r_autoPtr<tool> ptr3;
	ptr3 = ptr2;
	cout << ptr3->value<<endl;
	cout << ptr3.get() << endl;
	
}