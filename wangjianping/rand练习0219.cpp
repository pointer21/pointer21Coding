#include<iostream>
#include<time.h>
#include<math.h>
using namespace std;
void run2()
{
	//5��25��
	rand() % 20 + 5;
	//0��20
	rand() % 20;
}
//����0��100�������жϳɹ���
bool run(int n)
{
	rand();
	int p = rand() % 100;
	if (p<=n)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//����0��1 ��С���жϳɹ�
bool run3(double n)
{
	
	double p = ((double)rand())/RAND_MAX;
	if (p < (n))
	{
		cout << p << endl;
		return true;
	}
	else
	{
		cout << p << endl;
		return false;
	}
}
int main()
{
	run3(0.1);
	int t = 0, f = 0;
	srand(time(0));
	for (int i = 0; i < 100;i++)
	{
		if (run3(0.0550))
		{
			t++;
		}
		else
		{
			f++;
		}
	}
	cout << t << "�α���" << "  " << f << "��û����" << endl;

	return 0;
}