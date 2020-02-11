#include <iostream>
#include <vector>
using namespace std;
class people
{
	char *c;
public:
	people()
	{
		c = (char *)malloc(sizeof(char));
	}
	people(const people& p)
	{
		cout << "拷贝构造函数" << endl;
	}
	~people()
	{
		free(c);
		cout << "~people析构函数" << endl;
	}
};
void print(people p)
{

}
int main()
{
	
	people p;
	print(p);
	return 0;
}