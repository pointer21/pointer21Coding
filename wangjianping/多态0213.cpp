#include<iostream>

using namespace std;
class people
{
private:
public:
	int age;
	people()
	{
		cout << "����people" << endl;
	}
	virtual ~people()
	{
		cout << "����people" << endl;
	}
	virtual void dowork()
	{
		cout << "�Է�˯��" << endl;
	}
};
class worker : public people
{
public:
	 void dowork()
	{
		cout << "�ϰ�" << endl;
	}
	 virtual ~worker()
	 {
		 cout << "����worker" << endl;
	 }
};
class famer : public people
{
public:
	 void dowork()
	{
		cout << "�ֵ�" << endl;
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

