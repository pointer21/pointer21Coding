#include<iostream>

using namespace std;
class people
{
private:
public:
	int age;
	people()
	{
		cout << "构造people" << endl;
	}
	virtual ~people()
	{
		cout << "析构people" << endl;
	}
	virtual void dowork()
	{
		cout << "吃饭睡觉" << endl;
	}
};
class worker : public people
{
public:
	 void dowork()
	{
		cout << "上班" << endl;
	}
	 virtual ~worker()
	 {
		 cout << "析构worker" << endl;
	 }
};
class famer : public people
{
public:
	 void dowork()
	{
		cout << "种地" << endl;
	}
};
void marry(people* p)
{
	p->dowork();
}
int main2()
{
	people *w = new worker;
	w->dowork();
	marry(new people);
	marry(new worker);
	marry(new famer);
	delete w;
	return 0;
}

