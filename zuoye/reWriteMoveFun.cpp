#include <iostream>
#include <vector>
#include <string>
using namespace std;
class people
{
	string person;
public:
	people()
	{
		cout << "��ͨ���캯��" << endl;
	}
	people(people && p)
	{
		cout << "�ƶ����캯��" << endl;
	}
	~people()
	{
		cout << "��������" << endl;
	}
};


int main()
{
	using VE = vector<people>;
	using PE = people;
	PE p;
	VE ve;
	ve.push_back(move(p));
	ve.pop_back();
	return 0;
}