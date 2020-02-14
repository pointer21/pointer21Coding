#include<iostream>
#include<vector>
#include<string>
#include<Initializer_List>
#include<assert.h>
using namespace std;

class school{
protected:
	string schoolname;
	string schooltype;
	string address;

	void schoolopens(){
		cout << this->schoolname << "开学了" << endl;
	}
};
class University :public school{
	int b;
public:
	University() :school(){
		cout << "大学的构造函数" << endl;
	}
};
class highSchool :public school{
	int b;
public:
	highSchool() :school(){
		cout << "高中的构造函数" << endl;
	}
};
//class vec{
//	int* obj;
//public:
//	vec(initializer_list<double>arr){
//		cout << "参数初始化" << endl;
//		obj = new int[arr.size()];
//		for (int i = 0; i < arr.size();i++){
//			obj[i] = *(arr.begin()) ;
//		}
//	}
//	vec(double t){
//		cout << "单参数构造" << endl;
//	}
//	vec(double a, double b,double c){
//
//	}
//	int& operator[](unsigned int index){
//		return obj[index];
//	}
//};
class tool{
public:
	tool(){
		cout << "tool构造了" << endl;
	}
	tool(int){
		cout << "单参数构造了" << endl;
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
	tool& operator=(tool&&){
		cout << "tool移动赋值了" << endl;
		return *this;
	}
	tool& operator=(const tool&){
		cout << "tool拷贝赋值了" << endl;
		return *this;
	}
};
class vec{
	vector<int>arr;
public:
	vec(initializer_list<int>list){

	}
	int& operator[](int dex){
		assert(dex>0 && dex<arr.size());
		printf("%d\n", dex);
		return arr[dex];
	}
	int& at(int dex){
		assert(dex>0 && dex<arr.size());
		printf("%d\n", dex);
		return arr[dex];
	}
};
int main()
{
	vec arr{ 1, 2, 3, 4, 5, 6, 7 };
	cout << arr[-1] << endl;
}
