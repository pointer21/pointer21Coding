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
		cout << "�������캯��" << endl;
	}
	~people()
	{
		free(c);
		cout << "~people��������" << endl;
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