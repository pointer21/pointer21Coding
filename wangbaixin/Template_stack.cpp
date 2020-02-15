#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
//类模板

//template封装vector实现stack
template<class T> class r_stack
{
	vector<T> vec;
public:
	void push(T p)
	{
		vec.push_back(p);
	}
	void pop()
	{
		vec.pop_back();
	}
	T top()
	{
		return vec.back();
	}
	size_t size()
	{
		return vec.size();
	}
	bool empty()
	{
		return vec.size() == 0 ? true : false;
	}

};
void main3()
{
	r_stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << s.empty() << endl;
	cout << s.top() << endl;
	s.pop();
	cout << s.size() << endl;

	stack<int> s1;
	s1.
}