#pragma once
//模板化，可以接受任意类型
//构造方法，赋值一个指针
//析构函数，释放指针

//不标准的复制构造（转移内部指针控制权）
//不标准的复制赋值（转移内部指针控制权）
//reset 释放之前的，获得新的指针
//release 释放控制权，返回指针
//operator *() 模拟指针访问方法
//operator ->() 模拟指针箭头式访问方法
//get()  获得指向指针指向的指针
template<class T>
class r_autoPtr
{
	T* ptr=nullptr;
public:
	r_autoPtr(T* tem) :ptr(tem)
	{
	}
	r_autoPtr() = default;
	~r_autoPtr()
	{
		delete ptr;
	}
	r_autoPtr(r_autoPtr<T>& tem)
	{
		ptr = tem.ptr;
		tem.ptr = nullptr;
	}
	r_autoPtr<T>& operator= (r_autoPtr<T>& tem)
	{
		delete ptr;
		ptr = tem.ptr;
		tem.ptr = nullptr;
		return *this;
	}
	void reset(T* tem)
	{
		delete ptr;
		ptr = tem.ptr;
	}
	T* release()
	{
		auto tem = ptr;
		delete ptr;
		return tem;
	}
	T& operator*()
	{
		return *ptr;
	}
	T* operator->()
	{
		return ptr;
	}
	T* get()
	{
		return ptr;
	}
};