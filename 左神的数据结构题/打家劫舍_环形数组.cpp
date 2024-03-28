#include<iostream>
#include<vector>
using namespace std;
int robRange(vector<int>& nums, int start, int end);

//从左往右模型
//获取最高偷窃值
//nums[0....i],i代表下标索引
// 
//int process(vector<int>nums, int i)
//{
//	if (i == 0)
//	{
//		return nums[i];
//	}
//	if (i == 1)
//	{
//		return max(nums[0], nums[i]);
//	}
//	//选择当前的下标i
//	int p1 = 0;
//	if (i - 2 >= 0) p1 = nums[i] + process(nums, i - 2);
//	//不选择当前的下标i
//	int p2 = process(nums, i - 1);
//	return max(p1, p2);
//}

//动态规划版本
int rob(vector<int>& nums) {
    if (nums.size() == 0 ) return 0;
    if (nums.size() == 1) return nums[0];
    int result1 = robRange(nums, 0, nums.size() - 2); // 情况二
    int result2 = robRange(nums, 1, nums.size() - 1); // 情况三
    return max(result1, result2);
}
// 198.打家劫舍的逻辑
int robRange(vector<int>& nums, int start, int end) {
    if (end == start) return nums[start];
    vector<int> dp(nums.size());
    dp[start] = nums[start];
    dp[start + 1] = max(nums[start], nums[start + 1]);
    for (int i = start + 2; i <= end; i++) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[end];
}




int main1219()
{
	vector<int>nums = { 2,7,5,6,6,3,2,1,5};
	int size = nums.size() - 1;
	cout << "动态规划版本的最大值：" << rob(nums) << endl;
	return 0;
}