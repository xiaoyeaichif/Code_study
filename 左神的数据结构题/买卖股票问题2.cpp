#include<iostream>
#include<vector>
using namespace std;

//本题的要求是股票当天买就可以当天卖,也可以选择在这之后的某天卖出

int maxproift(vector<int>& nums)
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

int main01210()
{
	vector<int>nums = { 7,1,2,3,4,8,3,2,1,5};
	cout << "贪心算法的代码:" << maxproift(nums) << endl;
	return 0;
}