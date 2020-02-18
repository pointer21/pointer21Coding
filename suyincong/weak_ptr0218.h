#pragma once

	template<class T>
	class LweakPtr{
		Ref<T>* ref = nullptr;
	public:
		LweakPtr() = default;
		LweakPtr(LSharedPtr<T>& other):ref(other.ref){
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
			swap(ref,other.ref);
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
			swap(ref,other.ref);
		}
		void reset(){
			ref->reduce_w();
			ref = nullptr;
		}
	};
	template<class T,class ...args>
	LSharedPtr<T> 
	make_Lshared(args... a){
		//将ref对象和T对象在一起创建。
		//创建一次ref对象，在new T对象
		LSharedPtr<T> t(new T(a...));
		return t;
	}
}
