#include<iostream>
#include<vector>
#include<string>
#include<Initializer_List>
using namespace std;


class vec
{
private:
	int* obj;

public:
	vec(initializer_list<int>arr)
	{
		for (auto i = arr.begin(); i != arr.end();i++)
		{
			cout << *i;
		}
		cout << endl;
		obj = new int[arr.size()];
		for (int i = 0; i < arr.size();i++)
		{
			obj[i] = *(arr.begin()+1);
		}
	}
	int& operator[] (unsigned int index)
	{
		return obj[index];
	}
};
int main2()
{
	int arr[] = {1,2,3,4,5,6};
	vec v({ 1, 2, 3, 4, 5, 6 });
		v[2]=5;
	cout << v[2] << endl;
	return 0;
}
