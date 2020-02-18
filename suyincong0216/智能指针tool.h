#pragma once
//模板化，可以接受任意类型
//构造方法，赋值一个指针
//析构方法，释放一个指针
//不标准的复制构造（转移内部指针控制权）
//不标准的复制赋值（转移内部指针控制权）
//reset 释放之前的，获得新的指针
//release() 释放控制权，返回指针
//operator*()模拟指针访问方法
//operator->() 模拟指针箭头访问方法
//get() 获得指针指向的指针
template<class T>
class S_autoPtr{
	T* obj = nullptr;
public:
	S_autoPtr(T* ptr) : obj(ptr){
	}
	S_autoPtr() = default;
	~S_autoPtr(){
		delete obj;
	}
	S_autoPtr(S_autoPtr<T>& ptr){
		obj = ptr.obj;
		ptr.obj = nullptr;
	}
	S_autoPtr& opertor = (S_autoPtr<T>& ptr){
		delete obj;
		obj = ptr.obj;
		ptr.obj = nullptr;
		return *this;
	}
	void reset(T* newPtr){
		delete obj;
		obj = newPtr;
	}
	T* release(){
		auto temP = obj;
		obj = nullptr;
		return temP;
	}
	T& operator*(){
		return *obj;
	}
	T& operator->(){
		return obj;
	}
	T* get(){
		return obj;
	}
};