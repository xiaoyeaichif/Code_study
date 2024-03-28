#include<iostream>
#include<vector>
using namespace std;

int getmax1(vector<int>& nums)
{
	int ans = INT_MIN;
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i+1; j < nums.size(); j++)
		{
			if (nums[j] > nums[i])
			{
				ans = max(ans, nums[j] - nums[i]);
			}
		}
	}
	return ans == INT_MIN ? 0 : ans;
}
//̰���㷨�ҵ���Сֵ�Ҳ�����ֵ
int getmaxTX(vector<int>& nums)
{
	int N = nums.size();
	//��¼�����Сֵ
	//int pre = INT_MAX;
	int pre = nums[0];
	//��¼��������ֵ
	int ans = 0;
	for (int i = 1; i < N; i++)
	{
		pre = min(pre, nums[i]);
		ans = max(ans, nums[i] - pre);
	}
	return ans;

}

int main01280121()
{
	vector<int> nums = { 7,6,4,1,9,1,2,3,5 };
	cout << "�����ⷨ�Ĵ�:" << getmax1(nums) << endl;
	cout << "̰�Ľⷨ�Ĵ�:" << getmaxTX(nums) << endl;
	return 0;
}