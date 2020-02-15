#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A
{
public:
	int *p ;
	int value;

	A(int val)
	{
		value = val;
		p= new int[100];
	}
	A(const A& other)
	{
		p = new int[100];	
		value = other.value;	
		cout << "¿½±´¹¹Ôì" << endl;
	} 
	~A()
	{
		cout << "XIGOU" << endl;
		delete p; 
	}
	A& operator=(A& a)
	{
		delete p;
		p = new int[100]; 
		value = a.value;
		return *this;
	}
};
void Wswap(A& a, A& b)
{
	A tem = a;
	a = b;
	b = tem; 
}
void main2()
{
	
	A a(32); A b(64);
	
	Wswap(a,b);
	cout << a.value <<" "<< b.value << endl;
}