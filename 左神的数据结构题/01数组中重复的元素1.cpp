#include<iostream>
#include<vector>
using namespace std;

//在数组中的数字为0-n，数组长度为n+1,数组中只有一个数字出现两次,不使用额外空间求出数组中重复的数字
int find_o(vector<int>& res)
{
	//边界条件
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