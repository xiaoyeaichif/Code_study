#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//找到数组中,三元组的和为target
vector<vector<int>> ThreeSum(vector<int>& nums, int target)
{
	vector<vector<int>>ans;
	int N = nums.size();
	if (N < 3) return {};
	sort(nums.begin(), nums.end());
	for (int i = 0; i < N; i++)
	{
		//如果target == 0,数组的第一个元素大于0,则不需要计算
		//只要从下标i开始的数字大于target 就不用算后面的数了
		if (nums[i] > 0)
		{
			break;
		}
		//剪枝操作,类似于求组合拿到题
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}
		int left = i + 1;
		int right = N - 1;
		//两个下标不能重合，否则就不会出现三元组了
		while (left < right)
		{
			int res = nums[i] + nums[left] + nums[right];
			if (res == target)
			{
				ans.push_back({ nums[i] ,nums[left] ,nums[right] });
				while (right > left && nums[right] == nums[right - 1])
				{
					right--;
				}
				while (right > left && nums[left] == nums[left+1])
				{
					left++;
				}
				//还需要在移动一次,是因为最后指向的是重复的最后一个元素
				left++;
				right--;
			}
			else if (res > target)
			{
				right--;
			}
			else {
				left++;
			}
		}
	}
	return ans;
}

int main010901()
{
	vector<int>ans = { 0,-1,-1,1,1,2,-4,-1,2 };
	int target = 0;
	vector<vector<int>> nows = ThreeSum(ans, target);
	for ( vector<int> &now : nows )
	{
		for (int i : now)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}