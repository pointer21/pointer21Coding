#include<iostream>
#include<vector>
#include<memory>
using namespace std;

	template<class T>class L_autoPtr{
		T* obj = nullptr;
	public:
		L_autoPtr(T* ptr) :obj(ptr){
		}
		L_autoPtr() = default;
		~L_autoPtr(){
			delete obj;
		}
		L_autoPtr(L_autoPtr<T>& ptr) :obj(ptr.release()){

		}
		L_autoPtr& operator=(L_autoPtr<T>& ptr){
			obj = ptr.release();
			return *this;
		}
		void reset(T* newPtr = nullptr){
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
		T* operator->(){
			return obj;
		}
		T* get(){
			return obj;
		}

	};
	template<class T> class L_uniquePtr{
		T* obj = nullptr;
	public:
		L_uniquePtr(T* ptr) :obj(ptr){
		}
		L_uniquePtr(const T&) = delete;
		L_uniquePtr() = default;
		~L_uniquePtr(){
			delete obj;
		}
		L_uniquePtr& operator=(const L_autoPtr<T>&) = delete;
		L_uniquePtr(L_autoPtr<T>&& ptr) :obj(ptr.release()){

		}
		L_uniquePtr& operator=(L_autoPtr<T>&& ptr){
			obj = ptr.release();
			return *this;
		}
		void reset(T* newPtr = nullptr){
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
		T* operator->(){
			return obj;
		}
		T* get(){
			return obj;
		}
	};
	template<class T>class Ref{
		int r_count = 0;
		T* object = nullptr;
	public:
		Ref(T* target) :object(target){
			++r_count;
		}
		inline void increase(){
			r_count++;
		}
		inline void reduce(){
			r_count--;
			if (r_count == 0){
				delete object;
				delete this;
			}
		}
		T* get(){
			return object;
		}
		int getCount(){
			return r_count;
		}
	};
	template<class T> class LSharedPtr{
		Ref<T>* ref = nullptr;
	public:
		LSharedPtr() = default;
		~LSharedPtr(){
			if (ref){
				ref->reduce();
			}
		}
		LSharedPtr(T* newP){
			ref = new Ref<T>(newP);
		}
		LSharedPtr(const LSharedPtr& other){
			ref = other.ref;
			if (ref){
				ref->increase();
			}
		}
		LSharedPtr(LSharedPtr&& other){
			swap(ref, other.ref);
		}
		LSharedPtr& operator=(const LSharedPtr& other){
			if (ref){
				ref->reduce();
			}
			ref = other.ref;
			if (ref){
				ref->increase();
			}
			return *this;
		}
		LSharedPtr& operator=(LSharedPtr&& other){
			if (ref){
				ref->reduce();
			}
			ref = other.ref;
			other.ref = nullptr;
			return *this;
		}
		void swap(LSharedPtr& other){
			swap(ref, other.ref);
		}
		void reset(T* target = nullptr){
			if (ref){
				ref->reduce();
			}
			if (target != nullptr){
				ref = new Ref<T>(target);
			}
			else{
				ref = nullptr;
			}
		}
		T& operator*(){
			if (ref){
				return *ref->get();
			}
			else{
				return *(T*)nullptr;
			}
		}
		T* operator->(){
			if (ref){
				return ref->get();
			}
			else{
				return (T*)nullptr;
			}
		}
		T* get(){
			if (ref){
				return ref->get();
			}
			else{
				return (T*)nullptr;
			}
		}
		int use_count(){
			if (ref){
				return ref->getCount();
			}
			else{
				return 0;
			}
		}
		bool unique(){
			if (ref){
				return ref->getCount() == 1;
			}
			else{
				return false;
			}
		}
		operator bool(){
			return ref != nullptr;
		}
	};
	class A
	{
	private:
		int number = 1;
	public:
		A()
		{
			number = 2;
			cout << "构造" << endl;
		}
		A(const A&)
		{
			number = 3;
			cout << "拷贝构造" << endl;
		}
		A(A&&)
		{
			number = 4;
			cout << "移动构造" << endl;
		}
		~A()
		{
			cout << "析构" << number << endl;
		}
		int getnumber()
		{
			return number;
		}
	};
	void  run()
	{
		LSharedPtr<A>ptr1(new A);
		cout << "当前引用计数" << ptr1.use_count() << endl;
		LSharedPtr<A> ptr2(ptr1);
		LSharedPtr<A> ptr3;
		ptr3 = ptr2;

	}
	int main()
	{
		run();
		return 0;
	}
