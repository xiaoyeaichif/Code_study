#include<iostream>
#include<vector>
using namespace std;
//nums 为一个nX5的矩阵
//每一行第一行个数为L，第二个为R，第三个为数列的首项，第四个为和，第五个为公差
vector<int> getChafenshuz(vector<vector<int>>nums)
{
	vector<int>ans(11, 0);//多开辟一个空间是因为num[1]+1会越界
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
	//第二遍
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