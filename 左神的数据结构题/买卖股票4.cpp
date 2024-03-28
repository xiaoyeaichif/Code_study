#include<iostream>
#include<vector>
using namespace std;

//可以买卖无数次获得的最大利润
int maxproift2(vector<int>& nums)
{
	//ans = 0代表当天买，当天卖的利润
	//第一天的利润只有0
	int ans = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		//nums[i] - nums[i - 1]代表隔天的利润
		//本题和加汽油那题非常像
		ans += max(0, nums[i] - nums[i - 1]);
	}
	return ans;
}


//给定max_k能获取的最大利润
int Max_profit(int max_k, vector<int>& profit)
{
	int N = profit.size();
	if (N == 0) return 0;
	//如果给定的max_k远大于数组长度的一半，那么相当于可以操作无数次
	if (max_k > N / 2) return maxproift2(profit);

	vector<vector<vector<int>>>dp(N, vector<vector<int>>(max_k + 1, vector<int>(2, 0)));
	//k == 0时候的初始化
	for (int i = 0; i < N; i++)
	{
		dp[i][0][0] = 0;
		dp[i][0][1] = INT_MIN;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = max_k; j >= 1; j--)
		{
			if (i == 0)
			{
				dp[i][j][0] = 0;
				//只能进行买,所以需要花费
				dp[i][j][1] = -profit[i];
				//i == 0处理完后，马上跳出
				continue;
			}
			dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + profit[i]);
			dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - profit[i]);
		}
	}
	return dp[N - 1][max_k][0];
}
int main1227()
{
	vector<int>nums = { 3,2,6,5,0,3 };
	int k = 2;
	cout << "给定次数能获取的最大利润为：" << Max_profit(k, nums) << endl;
	return 0;
}