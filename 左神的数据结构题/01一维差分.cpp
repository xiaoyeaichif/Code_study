#include<iostream>
#include<vector>
using namespace std;
//nums Ϊһ��nX3�ľ���
vector<int> getChafen(vector<vector<int>>nums)
{
	vector<int>ans(11,0);//�࿪��һ���ռ�����Ϊnum[1]+1��Խ��
	for (vector<int>num : nums)
	{
		ans[num[0]] += num[2];
		ans[num[1]+1] -= num[2];
	}
	for (int i = 1;i < ans.size();i++)
	{
		ans[i] += ans[i - 1];
	}
	return ans;
}

int main10312()
{
	vector<vector<int>>nums = { {2 ,5 ,3},{1, 4 ,-2},{5 ,9 ,-4},{0,3,5} };
	vector<int> ans = getChafen(nums);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}