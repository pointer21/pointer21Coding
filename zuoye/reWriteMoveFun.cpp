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
		cout << "普通构造函数" << endl;
	}
	people(people && p)
	{
		cout << "移动构造函数" << endl;
	}
	~people()
	{
		cout << "析构函数" << endl;
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