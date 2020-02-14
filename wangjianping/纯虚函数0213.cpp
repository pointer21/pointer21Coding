#include<iostream>
#include<vector>
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
	virtual void dowork() = 0;//纯虚函数
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
int main()
{
	vector<people*> pp = {new famer,new worker};
	pp[0]->dowork();
	pp[1]->dowork();
	return 0;
}

