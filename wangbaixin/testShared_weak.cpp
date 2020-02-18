#include "templat.h"
#include <iostream>
#include <string>
using namespace std;

class tool{
	
public:
	weak_PTR<tool> pre;//shared_PTR���͵�pre��next�ᵼ��ѭ������
	weak_PTR<tool> next;
	int value = 0;
	tool()
	{
		cout << "���캯��" << endl;
	}
	~tool()
	{
		cout << "~��������" << endl;
	}
};
void runShare()
{
	shared_PTR<tool> sptr1{ new tool };
	shared_PTR<tool> sptr2{ new tool };
	sptr1->next = sptr2;
	sptr2->pre = sptr1;
	cout << sptr1.use_count();
}
void main()
{
	runShare();
}