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
		cout << schoolname<<"��У��" << endl;
		delete master;
	}
	school(string schoolname,string schooltype,string address){
		cout << "��ͨ���캯��" << endl;
		this->schoolname = schoolname;
		this->schooltype = schooltype;
		this->address = address;
		master = new principal("����ʦ");
	}
	school(const school& p):schoolname(p.schoolname),schooltype(p.schooltype),address(p.address){
		schoolname = p.schoolname;
		cout << this->schoolname<<"����������" << endl;
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

school getschool(){
	school s2("����ʯ�ʹ�ѧ", "��ѧ", "����");
	return s2;
}
int main(){
	school s1("����ʯ�ʹ�ѧ", "��ѧ", "����");
	school s2(move(s1));
	cout << "��һ�����"<< endl;
}
