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
		cout << "朱老师下班了" << endl;
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
		cout << schoolname << "闭校了" << endl;
		delete master;
	}
	school(){
		cout << "无参默认构造函数" << endl;
	}
	school(string schoolname, string schooltype, string address){
		cout << "普通构造函数" << endl;
		this->schoolname = schoolname;
		this->schooltype = schooltype;
		this->address = address;
		master = new principal("朱老师");
	}
	school(const school& p) :schoolname(p.schoolname), schooltype(p.schooltype), address(p.address){
		schoolname = p.schoolname;
		cout << this->schoolname << "拷贝建立了" << endl;
		master = new principal(*(p.master));
	}
	//类默认的移动构造，和默认的拷贝构造效果
	school(school&& other) :schooltype(other.schooltype), schoolname(other.schoolname), address(other.address){
		cout << "移动构造" << endl;
		master = other.master;
		other.master = NULL;
	}

	void schoolopens(){
		cout << this->schoolname << "开学了" << endl;
	}
};
class University :public school{
	int b;
public:
	University():school("大庆指针","软件培训","大庆"){
		cout << "大学的构造函数" << endl;
	}
};
class highSchool :public school{
	int b;
public:
	highSchool() :school("衡水中学", "高中", "衡水"){
		cout << "高中的构造函数" << endl;
	}
};

//虚析构
class animal
{
public:
	animal()
	{
		cout << "animal构造函数已调用" << endl;
	}
	virtual ~animal()  //虚析构    虚析构与纯虚析构只能存在一个
	{
	    cout << "animal析造函数已调用" << endl;
	}
	
	virtual void speak() = 0;
};
class dog : public animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};


class cat : public animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};
void test01()
{
	animal* it = new cat;
	it->speak();
	delete it;
}

//隐藏与覆盖
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
