#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;
class Solution{
public:
	bool isAnagram(string s, string t){
		if (s.length() == 0 && t.length() == 0)
		{
			return true;
		}
		else if ((s.length() == 0 || t.length() == 0) || s.length() != t.length())
		{
			return false;
		}
		unordered_map<char,int> umap;
		for (int i = 0; i < s.length();i++)
		{
			//s[i] �Ƿ��ڹ�ϣ����
			//û�ڹ�ϣ�����в���
			if (umap.find(s[i]) == umap.end())
			{
				umap[s[i]] = 1;
			}
			else
			{
				umap[s[i]]++;
			}
		}
		//����t�ַ���
		for (int i = 0; i < t.length();i++)
		{
			if (umap.empty())
			{
				return false;
			}
			//t[i]û�ڹ�ϣ����
			if (umap.find(t[i]) == umap.end())
			{
				return false;
			}
			else
			{
				umap[t[i]]--;
				if (umap[t[i]] == 0)
				{
					umap.erase(t[i]);
				}
			}
		}
		if (!umap.empty())
		{
			return false;
		}
		return true;
	}
};



int main()
{
	vector<int>vec = { 1, 2, 2, 3, 3, 3, 4, 5 };
	vector<int>::iterator it = vec.begin();
	for (; it != vec.end();it++)
	{
		if (*it == 3)
		{
			it = vec.erase(it);
			it--;
		}
	}
	for (int i = 0; i < vec.size();i++)
	{
		cout << vec[i] << endl;
	}
	return 0;
}