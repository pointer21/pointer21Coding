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
		cout << "��ͨ���캯��" << endl;
	}
	people(const people& p)
	{
		cout << "�������캯��" << endl;
	}
	void print()
	{
		cout << this->person<<endl;
	}
	~people()
	{
		cout << "��������" << endl;
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