#include <iostream>
#include <vector>
using namespace std;
int main2()
{
	vector<int> a = {1,2,3,4,5,6};
	try
	{
		for (int i = 0; i < 7;i++)
		{
			cout <<a.at(i)<< endl;
		}
		cout << "输出完成";
	}
	catch (...)
	{
		cout << "异常" << endl;
	}
	
	return 0;
}