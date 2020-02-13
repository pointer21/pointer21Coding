#include<iostream>
#include<string>

using namespace std;
class principal{
	string name;
public:
	principal(string sname){
		this->name = sname;
	}
	~principal(){
		cout << "����ʦ�°���" << endl;
	}
};

class school{
protected:
	string schoolname;
	string schooltype;
	string address;

public:
	principal* master;
	~school(){
		cout << schoolname << "��У��" << endl;
		delete master;
	}
	school(){
		cout << "�޲�Ĭ�Ϲ��캯��" << endl;
	}
	school(string schoolname, string schooltype, string address){
		cout << "��ͨ���캯��" << endl;
		this->schoolname = schoolname;
		this->schooltype = schooltype;
		this->address = address;
		master = new principal("����ʦ");
	}
	school(const school& p) :schoolname(p.schoolname), schooltype(p.schooltype), address(p.address){
		schoolname = p.schoolname;
		cout << this->schoolname << "����������" << endl;
		master = new principal(*(p.master));
	}
	//��Ĭ�ϵ��ƶ����죬��Ĭ�ϵĿ�������Ч��
	school(school&& other) :schooltype(other.schooltype), schoolname(other.schoolname), address(other.address){
		cout << "�ƶ�����" << endl;
		master = other.master;
		other.master = NULL;
	}

	void schoolopens(){
		cout << this->schoolname << "��ѧ��" << endl;
	}
};
class University :public school{
	int b;
public:
	University():school("����ָ��","�����ѵ","����"){
		cout << "��ѧ�Ĺ��캯��" << endl;
	}
};
class highSchool :public school{
	int b;
public:
	highSchool() :school("��ˮ��ѧ", "����", "��ˮ"){
		cout << "���еĹ��캯��" << endl;
	}
};

//������
class animal
{
public:
	animal()
	{
		cout << "animal���캯���ѵ���" << endl;
	}
	virtual ~animal()  //������    �������봿������ֻ�ܴ���һ��
	{
	    cout << "animal���캯���ѵ���" << endl;
	}
	
	virtual void speak() = 0;
};
class dog : public animal
{
public:
	void speak()
	{
		cout << "С����˵��" << endl;
	}
};


class cat : public animal
{
public:
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};
void test01()
{
	animal* it = new cat;
	it->speak();
	delete it;
}

//�����븲��
class father
{
public:
	void show1()
	{
		cout << "father::show1" << endl << endl;
	}

	virtual void show2()
	{
		cout << "father::show2" << endl << endl;
	}
};

class son :public father
{
public:
	void show1()
	{
		cout << "son::show1" << endl << endl;
	}

	virtual void show2()
	{
		cout << "son::show2" << endl << endl;
	}
};

int main()
{
    test01();

	father f;
	son s;

	father *pf = &s;
	son *ps = &s;

	pf->show1();
	pf->show2();

	return 0;
}
