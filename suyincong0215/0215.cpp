#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

class tool{
public:
	tool(){
		cout << "tool������" << endl;
	}
	tool(int t){
		cout << "������������,������t" << t << endl;
	}
	tool(const tool&){
		cout << "tool����������" << endl;
	}
	tool(tool&&){
		cout << "tool�ƶ�������" << endl;
	}
	~tool(){
		cout << "tool������" << endl;
	}
	tool& operator = (tool&&){
		cout << "tool�ƶ���ֵ��" << endl;
		return *this;
	}
	tool& operator = (const tool&){
		cout << "tool������ֵ��" << endl;
		return *this;
	}
};

int Lmax(int a, int b){
	return a > b ? a : b;
}
double Lmax(double a, double b){
	return a > b ? a : b;
}
long long Lmax(long long a, long long b){
	return a > b ? a : b;
}
//��ģ�壬����ģ��//class�ȼ�typename
template<int d,class T2,class T1,class T3>Lmax(T2 a, T1 b,T3){
	int arr[d];
	cout << d << endl;
	cout << "ģ���Ƶ�����" << endl;
	return a > b ? a : b;
}




//Lswap����
//template<class T> void Lswap(T& a, T& b){
//	T tem = a;
//	a = b;
//	b = tem;
//}
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
Lprint();
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
	Lprint_3(d...);
}
//�������ͣ�ģ��д���룬���ݵ��õĲ�ͬ�������Ƶ��������汾����ͨ���롣
int main()
{
	Lprint_3(2, 3, 2, 6, 2, 3, 5);
	//Lprint(2,3.0,5,"123");


	int x = 2, y = 3;
	double a = 1.1, b = 1.2;
	//��ʾ�Ƶ�
	cout << Lmax<2>(x, y,a) << endl;
	//��ʾ�Ƶ�
	cout << Lmax<2>(x, y,a) << endl;
	//��ʾָ��ģ��,������ģ���Ƶ�����
	cout << Lmax<3>(a, b,a) << endl;
}

