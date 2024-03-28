#include<iostream>
#include<vector>
using namespace std;

//�������е�����Ϊ0-n�����鳤��Ϊn+1,������ֻ��һ�����ֳ�������,��ʹ�ö���ռ�����������ظ�������
int find_o(vector<int>& res)
{
	//�߽�����
	for (int i = 0; i < res.size(); i++)
	{
		if (res[i] > res.size() - 1 || res[i] < 0)
		{
			return -1;
		}
	}
	for (int i = 0; i < res.size(); i++)
	{
		while (res[i] != i)
		{
			if (res[i] == res[res[i]])
			{
				return res[i];
			}
			swap(res[i], res[res[i]]);
		}
	}
	return -1;
}




int main021601()
{
	vector<int>res = { 1,1,0,4,2,3 };
	int ans = find_o(res);
	cout << ans << endl;
	return 0;
}