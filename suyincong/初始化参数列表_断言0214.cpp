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
		cout << this->schoolname << "��ѧ��" << endl;
	}
};
class University :public school{
	int b;
public:
	University() :school(){
		cout << "��ѧ�Ĺ��캯��" << endl;
	}
};
class highSchool :public school{
	int b;
public:
	highSchool() :school(){
		cout << "���еĹ��캯��" << endl;
	}
};
//class vec{
//	int* obj;
//public:
//	vec(initializer_list<double>arr){
//		cout << "������ʼ��" << endl;
//		obj = new int[arr.size()];
//		for (int i = 0; i < arr.size();i++){
//			obj[i] = *(arr.begin()) ;
//		}
//	}
//	vec(double t){
//		cout << "����������" << endl;
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
		cout << "tool������" << endl;
	}
	tool(int){
		cout << "������������" << endl;
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
	tool& operator=(tool&&){
		cout << "tool�ƶ���ֵ��" << endl;
		return *this;
	}
	tool& operator=(const tool&){
		cout << "tool������ֵ��" << endl;
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
