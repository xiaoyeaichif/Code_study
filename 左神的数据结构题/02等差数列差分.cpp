#include<iostream>
#include<vector>
using namespace std;
//nums Ϊһ��nX5�ľ���
//ÿһ�е�һ�и���ΪL���ڶ���ΪR��������Ϊ���е�������ĸ�Ϊ�ͣ������Ϊ����
vector<int> getChafenshuz(vector<vector<int>>nums)
{
	vector<int>ans(11, 0);//�࿪��һ���ռ�����Ϊnum[1]+1��Խ��
	for (vector<int>num : nums)
	{
		ans[num[0]] += num[2];
		ans[num[0] + 1] += num[4]-num[2];
		ans[num[1] + 1] += -num[4] - num[3];
		ans[num[1] + 2] +=   num[3];
	}
	for (int i = 1; i < ans.size(); i++)
	{
		ans[i] += ans[i - 1];
	}
	//�ڶ���
	for (int i = 1; i < ans.size(); i++)
	{
		ans[i] += ans[i - 1];
	}
	return ans;
}





int main1117()
{
	vector<vector<int>>nums = { {2 ,6 ,4,16,3} };
	vector<int> ans = getChafenshuz(nums);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}