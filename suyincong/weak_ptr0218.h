#pragma once

	template<class T>
	class LweakPtr{
		Ref<T>* ref = nullptr;
	public:
		LweakPtr() = default;
		LweakPtr(LSharedPtr<T>& other):ref(other.ref){
			cout << "ʹ��shread_����һ��weak�Ŀ����� ֵ�����" << endl;
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
			cout << "������weak�Ŀ�����ֵ�����" << endl;
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
			cout << "������weak���ƶ���ֵ�����" << endl;
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
		//��ref�����T������һ�𴴽���
		//����һ��ref������new T����
		LSharedPtr<T> t(new T(a...));
		return t;
	}
}
