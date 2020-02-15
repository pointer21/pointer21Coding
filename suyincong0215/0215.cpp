#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

class tool{
public:
	tool(){
		cout << "tool构造了" << endl;
	}
	tool(int t){
		cout << "单参数构造了,参数是t" << t << endl;
	}
	tool(const tool&){
		cout << "tool拷贝构造了" << endl;
	}
	tool(tool&&){
		cout << "tool移动构造了" << endl;
	}
	~tool(){
		cout << "tool析构了" << endl;
	}
	tool& operator = (tool&&){
		cout << "tool移动赋值了" << endl;
		return *this;
	}
	tool& operator = (const tool&){
		cout << "tool拷贝赋值了" << endl;
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
//类模板，函数模板//class等价typename
template<int d,class T2,class T1,class T3>Lmax(T2 a, T1 b,T3){
	int arr[d];
	cout << d << endl;
	cout << "模板推导函数" << endl;
	return a > b ? a : b;
}




//Lswap函数
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
//类模板封装vector实现stack
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



//模板参数包  递归拆包
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
	cout << "递归拆包终结" << endl;
}
template<class T, class... args> void Lprint(T f, args... d){
	cout << f << endl;
	Lprint(d...);
}
template<class T, class T2, class T3, class... args> void Lprint_3(T f, T2 f2, T3 f3, args... d){
	cout << "第一个" << f << "第二个" << f2 << "第三个" << f3 << endl;
	Lprint_3(d...);
}
//代码膨胀，模板写代码，根据调用的不同，他会推导出完整版本的普通代码。
int main()
{
	Lprint_3(2, 3, 2, 6, 2, 3, 5);
	//Lprint(2,3.0,5,"123");


	int x = 2, y = 3;
	double a = 1.1, b = 1.2;
	//显示推导
	cout << Lmax<2>(x, y,a) << endl;
	//隐示推导
	cout << Lmax<2>(x, y,a) << endl;
	//显示指定模板,必须用模板推导函数
	cout << Lmax<3>(a, b,a) << endl;
}

