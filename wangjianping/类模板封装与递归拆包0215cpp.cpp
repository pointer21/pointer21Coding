#include<iostream>
#include<vector>
#include<string>
#include<assert.h>
#include<Initializer_List>
using namespace std;

class tool{
public:
	tool(){
		cout << "����" << endl;
	}
	tool(int t){
		cout << "����������" << t << endl;
	}
	tool(const tool&){
		cout << "��������" << endl;
	}
	tool(tool&&){
		cout << "�ƶ�����" << endl;
	}
	~tool(){
		cout << "����" << endl;
	}
	tool& operator = (tool&&){
		cout << "�ƶ���ֵ" << endl;
		return *this;
	}
	tool& operator = (const tool&){
		cout << "������ֵ" << endl;
		return *this;
	}
};

template<class T> void Lswap(T& a, T& b){
	T tem = std::move(a);
	a = std::move(b);
	b = std::move(tem);
}
//��ģ���װvectorʵ��stack
template<class T> class L_stack{
	std::vector<T> arr;
public:
	void push(T&& obj){
		arr.push_back(obj);
	}
	void pop(){
		arr.pop_back();
	}
	T& top(){
		return arr.back();
	}
	size_t size(){
		return arr.size();
	}
	bool empty(){
		return arr.empty();
	}
};

//ģ�������  �ݹ���
void Lprint(const char* f){
cout << f << endl;
Lprint(f);
}
void Lprint(int f,const char* d){
cout << f << endl;
Lprint(d);
}
void  Lprint(double f, int d1, const char* d2){
cout << f << endl;
Lprint(d1,d2);
}
void Lprint(int f,double d1,int d2,const char* d3){
cout << f << endl;
Lprint(d1,d2,d3);
}
void Lprint(){
	cout << "�ݹ����ս�" << endl;
}
template<class T, class... args> void Lprint(T f, args... d){
	cout << f << endl;
	Lprint(d...);
}
template<class T, class T2, class T3, class... args> void Lprint_3(T f, T2 f2, T3 f3, args... d){
	cout << "��һ��" << f << "�ڶ���" << f2 << "������" << f3 << endl;
	Lprint(d...);
}
int main()
{
	Lprint_3(2, 3, 2, 6, 2, 3, 5);
}

