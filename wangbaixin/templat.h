#pragma once

using namespace std;

template<class T> 
class unique_PTR
{
	T *ptr=nullptr;
public:
	unique_PTR(T *ptr) :ptr(ptr)//构造函数
	{
	}
	unique_PTR() = default;
	unique_PTR(const unique_PTR<T>&) = delete;//不能拷贝构造,AND不能执行赋值操作
	~unique_PTR()//析构函数
	{
		delete ptr;
	}

	unique_PTR<T>(unique_PTR<T>&& other)//移动构造
	{
		swap(ptr, other.ptr);
	}
	unique_PTR<T>& operator=(unique_PTR<T>&& other)//移动赋值
	{
		swap(ptr, other.ptr);
		*this;
	}
	T* release()
	{
		auto tem = ptr;
		delete ptr;
		return tem;
	}
	void reset(T* tem)
	{
		delete ptr;
		ptr = tem;
	}
	T* get()
	{
		return ptr;
	}
	void get_deleter()
	{
		delete ptr;
	}
	operator bool()
	{
		return ptr != nullptr;
	}
	T& operator*()
	{
		return *ptr;
	}
	T* operator->()
	{
		return ptr;
	}
	unique_PTR<T>& operator[](T& i)
	{
		return ptr[i];
	}
	
};

template<class T>
/*无参构造，传递指针构造，拷贝构造，移动构造，拷贝赋值，移动赋值,交换，析构函数
 reset(T*)替换对象。 reset() 销毁对象
 operator*() operator->()
 get()获得裸指针
 use_count() 获得引用计数
 unique() 判断当前是否唯一  use_count()==1
 operator bool() 是否关联对象*/
class Ref//资源计数类
{
	int r_count=0;//shared指针计数
	int w_count=0;//弱引用指针计数
	T* obj;
public:
	Ref(T* target) :obj(target)
	{
		r_count++;
	}
	inline void r_increase()
	{
		r_count++;
	}
	inline void w_increase()
	{
		w_count++;
	}
	inline void reduce(){
		r_count--;
		if (r_count==0)//没有shared_ptr指向引用计数
		{
			delete obj;
			obj = nullptr;
			if (w_count==0)//没有weak_ptr
			{
				delete this;
			}
		}
	}
	inline void reduce_w(){
		w_count--;
		if (w_count == 0)//没有weak_ptr
		{
			delete obj;
			delete this;
		}
	
	}
	T* get(){
		return obj;
	}
	int getCount(){
		return r_count;
	}
};

template<class T> class weak_PTR;
template<class T>
class shared_PTR
{
	Ref<T> *ref=nullptr;
	friend class weak_PTR<T>;
public:
	shared_PTR<T>() = default;
	shared_PTR<T>(Ref<T>* newp)
	{
		ref = newp;
		if (ref)
		{
			ref->r_increase();
		}
	}
	shared_PTR<T>(T* newp)
	{
		ref = new Ref<T>(newp);
	}
	//拷贝构造
	shared_PTR<T>& hared_PTR(const shared_PTR<T>& other)
	{
		ref = other.ref;
		if (ref)
		{
			ref->increase();
		}
		return *this;
	}
	//移动构造
	shared_PTR<T>& hared_PTR(shared_PTR<T>&& other)
	{
		swap(ref, other.ref);
	}
	//拷贝赋值
	shared_PTR<T>& operator=(const shared_PTR<T>& other)
	{
		if (ref)
		{
			ref->reduce();
		}
		ref = other.ref;
		if (ref)
		{
			ref->r_increase();
		}
		return *this;
	}
	//移动赋值
	shared_PTR<T>& operator=(shared_PTR<T>&& other)
	{
		if (ref)
		{
			ref->reduce;
		}
		swap(ref, other->ref);
		return *this;
	}
	void swap(shared_PTR<T>& other)
	{
		swap(ref, other.ref);
	}
	~shared_PTR<T>()
	{
		if (ref)
		{
			ref->reduce();
		}
	}
	void reset(T* target=nullptr)
	{
		if (ref){
			ref->reduce();
		}
		if (target!=nullptr){
			ref = new Ref<T>(target);
		}
		else
		{
			ref=nullptr;
		}
	}
	T& operator*()
	{
		if (ref){
			return *ref->get();
		}
		else
		{
			return *(T*)nullptr;
		}
	}
	T* operator->()
	{
		if (ref){
			return ref->get();
		}
		else
		{
			return (T*)nullptr;
		}
	}
	T* get()
	{
		if (ref){
			return ref->get();
		}
		else
		{
			else
			{
				return (T*)nullptr;
			}
		}
	}
	int use_count()
	{
		if (ref){
			return ref->getCount();
		}
		else
		{
			return 0;
		}
	}
	bool unique()
	{
		if (ref){
			return ref->getCount() == 1;
		}
		else
		{
			return false;
		}
	}
	operator bool(){
		return ref != nullptr;
	}
};

template<class T>
class weak_PTR
{
	Ref<T> *ref = nullptr;
public:
	weak_PTR() = default;
	weak_PTR(shared_PTR<T>& other):ref(other.ref){
		if (ref){
			ref->w_increase();
		}
	}
	weak_PTR<T>(const weak_PTR<T>& other){
		if (ref){
			ref->w_increase();
		}
	}
	weak_PTR<T>(weak_PTR<T>&& other){
		swap(ref, other.ref);
	}
	weak_PTR<T> operator=(const weak_PTR<T>& other){
		if (ref){
			ref->reduce_w();
		}
		ref = other.ref;
		if (ref){
			ref->w_increase();
		}
		return *this;
	}
	weak_PTR<T> operator=(weak_PTR<T>&& other){
		if (ref){
	 		ref->reduce_w();
		}
		ref = other.ref;
		other.ref = nullptr;
		if (ref)
		{
			ref->w_increase();
		}
		return *this;
	}
	int use_count()
	{
		if (ref)
			return ref->getCount();
		else
			return 0;
	}
	bool expired()
	{
		if (ref)
			return ref->getCount() > 0;
		else
			return false;
	}
	shared_PTR<T> lock()
	{
		shared_PTR<T> tem(ref);
		return tem;
	}
	void swap(weak_PTR<T>& other)
	{
		swap(ref, other->ref);
	}
	void reset()
	{
		ref->reduce_w();//
		ref = nullptr;
	}
};



