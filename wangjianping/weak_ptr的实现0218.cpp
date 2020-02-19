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
			int w_count = 0;
			T* object = nullptr;
		public:
			Ref(T* target) :object(target){
				++r_count;
			}
			inline void increase(){
				r_count++;
			}
			inline void increase_w(){
				w_count++;
			}
			inline void reduce(){
				r_count--;
				if (r_count == 0){
					delete object;
					object = nullptr;
					if (w_count == 0){
						delete this;
					}
				}
			}
			inline void reduce_w(){
				w_count--;
				if (w_count == 0 && r_count == 0){
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
		template<class T>class LweakPtr{
			Ref<T>* ref = nullptr;
		public:
			LweakPtr() = default;
			LweakPtr(LSharedPtr<T>& other) :ref(other.ref){
				cout << "使用shread_构造一个weak的拷贝赋 值运算符" << endl;
				if (ref){
					ref->increase_w();
				}
			}
			LweakPtr(const LweakPtr<T>& other) :ref(other.ref){
				if (ref){
					ref->increase_w();
				}
			}
			LweakPtr(LweakPtr<T>&& other){
				swap(ref, other.ref);
			}
			LweakPtr<T>& operator = (const LweakPtr<T>& other){
				cout << "调用了weak的拷贝赋值运算符" << endl;
				if (ref){
					ref->reduce_w();
				}
				ref = other.ref;
				if (ref){
					ref->increase_w();
				}
				return *this;
			}
			LweakPtr<T>&  operator=(LweakPtr<T>&& other){
				cout << "调用了weak的移动赋值运算符" << endl;
				if (ref){
					ref->reduce_w();
				}
				ref = other.ref;
				other.ref = nullptr;
				return *this;
			}
			int use_count(){
				if (ref){
					return ref->getCount();
				}
				else{
					return 0;
				}
			}
			bool expired(){
				if (ref){
					return ref->getCount() > 0;
				}
				else{
					return false;
				}
			}
			LSharedPtr<T> lock(){
				LSharedPtr<T> tem(ref);
				return tem;
			}

			void sawp(LweakPtr<T>& other){
				swap(ref, other.ref);
			}
			void reset(){
				ref->reduce_w();
				ref = nullptr;
			}
		};
		template<class T, class ...args>LSharedPtr<T>make_Lshared(args... a){
				//将ref对象和T对象在一起创建。
				//创建一次ref对象，在new T对象
				LSharedPtr<T> t(new T(a...));
				return t;
			}
		class A
		{
		private:
			
		public:
			int number = 1;
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
			LSharedPtr<A>ptr1 = { new A };
			LSharedPtr<A> ptr2 = { new A };
			ptr1->number = (ptr2);

		}
		int main()
		{
			run();
			return 0;
		}
