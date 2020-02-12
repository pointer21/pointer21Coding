#include <iostream>
#include <vector>
#include <string>
using namespace std;
class people
{
	string person;
	
public:
	friend void outValue(people& p, string value);
	people()
	{
		cout << "普通构造函数" << endl;
	}
	people(const people& p)
	{
		cout << "拷贝构造函数" << endl;
	}
	void print()
	{
		cout << this->person<<endl;
	}
	~people()
	{
		cout << "析构函数" << endl;
	}
};
void outValue(people& p, string value)
{
	p.person = value;
}

int main2()
{
	using PE = people;
	PE p;
	outValue(p, "yang");
	p.print();
	
	return 0;
}