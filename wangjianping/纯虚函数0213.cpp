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
		cout << "����people" << endl;
	}
	virtual ~people()
	{
		cout << "����people" << endl;
	}
	virtual void dowork() = 0;//���麯��
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
int main()
{
	vector<people*> pp = {new famer,new worker};
	pp[0]->dowork();
	pp[1]->dowork();
	return 0;
}

