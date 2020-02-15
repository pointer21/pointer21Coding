#include <iostream>
#include <string>
using namespace std;
//模板参数包的递归拆包

void unback()
{
	cout << "拆最后的空包" << endl;
}
template<class firstArg, class...args> void unback(firstArg f, args...a)
{
	cout << f << endl;
	unback(a...);
}

void main()
{
	unback(1, 2, "fag", 4, 5);
}