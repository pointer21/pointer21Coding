#include<iostream>
#include<vector>
#include<memory>
#include<string>
using namespace std;
class tool
{
private:
public:
	tool()
	{
		cout << "构造了" << endl;
	}
	tool(const tool&)
	{
		cout << "拷贝构造了" << endl;
	}
	~tool()
	{
		cout << "析构了" << endl;
	}
 };
template<class T>
class L_autoptr
{
	T* obj = nullptr;
public:
	L_autoptr(T* ptr) :obj(ptr)
	{

	}
	L_autoptr() = default;
	~L_autoptr()
	{
		delete obj;
	}
	L_autoptr(L_autoptr<T>& ptr)
	{

	}
	L_autoptr& operator=(L_autoptr<T>& ptr)
	{
		delete obj;
		obj = ptr.obj;
		ptr.obj = nullptr;
		return *this;
	}
	void reset(T* newptr)
	{
		delete obj;
		obj = newptr;
	}
	T* release()
	{
		auto temp=obj;
		obj = nullptr;
		return trmp;
	}
	T& operator*()
	{
		return obj;
	}
	T* operator->()
	{
		return obj;
	}
	T* get()
	{
		return obj;
	}

};
void run()
{
	L_autoptr<tool>ptr1(new tool);
	L_autoptr<tool>ptr2(ptr1);
	L_autoptr<tool>ptr3;
	ptr3 = ptr2;

}


int main()
{
	//智能指针;
	run();
	return 0;
}
