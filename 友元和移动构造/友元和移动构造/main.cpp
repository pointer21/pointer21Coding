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
class A{
public:
	void run(school s){
		s.schoolname;
	}
};
class school{
	friend class A;
	string schoolname;
	string schooltype;
	string address;
	principal* master;
public:
	~school(){
		cout << schoolname<<"闭校了" << endl;
		delete master;
	}
	school(string schoolname,string schooltype,string address){
		cout << "普通构造函数" << endl;
		this->schoolname = schoolname;
		this->schooltype = schooltype;
		this->address = address;
		master = new principal("朱老师");
	}
	school(const school& p):schoolname(p.schoolname),schooltype(p.schooltype),address(p.address){
		schoolname = p.schoolname;
		cout << this->schoolname<<"拷贝建立了" << endl;
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

school getschool(){
	school s2("东北石油大学", "大学", "大庆");
	return s2;
}
int main(){
	school s1("东北石油大学", "大学", "大庆");
	school s2(move(s1));
	cout << "下一句代码"<< endl;
}
