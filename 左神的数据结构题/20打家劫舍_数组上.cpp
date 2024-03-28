#include<iostream>
#include<vector>
using namespace std;

//从左往右模型
//获取最高偷窃值
//nums[0....i],i代表下标索引
int process(vector<int>nums, int i)
{
	if (i == 0)
	{
		return nums[i];
	}
	if (i == 1)
	{
		return max(nums[0], nums[i]);
	}
	//选择当前的下标i
	int p1 = 0;
	if(i- 2 >= 0) p1 = nums[i] + process(nums, i - 2);
	//不选择当前的下标i
	int p2 = process(nums, i - 1);
	return max(p1, p2);
}

//动态规划版本
int dp(vector<int>nums)
{
	//边界
	if (nums.size() == 1) return nums[0];
	//由递归可知表的长度应该为i-0+1 = i+1；i代表的是下标
	int N = nums.size();
	vector<int>ans(N, 0);
	ans[0] = nums[0];
	ans[1] = max(nums[0], nums[1]);
	for (int i = 2; i < N; i++)
	{
		ans[i] = max(ans[i - 1], ans[i - 2] + nums[i]);
	}
	return ans[N - 1];
}

int main020()
{
	vector<int>nums = { 2,7,9,3,1 };
	int size = nums.size() - 1;
	cout << "递归版本的最大值：" << process(nums, size) <<endl ;
	cout << "动态规划版本的最大值：" << dp(nums) << endl;
	return 0;
}