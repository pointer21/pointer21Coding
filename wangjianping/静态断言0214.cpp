#include<iostream>
#include<vector>
#include<string>
#include<assert.h>
#include<Initializer_List>
using namespace std;


class vec
{
	vector<int> arr;
public: 
	vec(initializer_list<int>list) :arr(list)
	{

	}
	int& operator[](int dex)
	{
		assert(dex>0&&dex<arr.size());
		printf("%d\n",dex);
		return arr[dex];
	}
};
int main()
{
	vec arr{ 1, 2, 3, 4, 5, 6 };
	cout << arr[-2] << endl;
	return 0;
}
