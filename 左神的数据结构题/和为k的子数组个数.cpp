#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


//暴力解法
int Get_count_of_k(vector<int>& nums,int k)
{
	int count = 0;
	int sum;
	int length = nums.size();
	for (int i = 0; i < length; i++)
	{
		sum = nums[i];
		if (sum == k) count += 1;
		for (int j = i+1; j < length; j++)
		{
			sum += nums[j];
			if (sum == k)
			{
				count++;
			}
		}
	}
	return count;
}

//前缀和加哈希解决
int Get_count_of_k_1(vector<int>& nums, int k)
{
	int count = 0;
	int sum = 0;
	int length = nums.size();
	vector<int>Pre_sum(length + 1, 0);
	for (int i = 1; i < length + 1; i++)
	{
		Pre_sum[i] = nums[i - 1] + Pre_sum[i - 1];
	}
	//接下来使用哈希表找到数组Pre_sum中两数之差等于k的数字就行
	//也就是pre[j] - pre[i] == k
	//这就回到了两数之和的问题当中去了
	unordered_map<int, int>u_map;
	for (int i = 1; i < length+1; i++)
	{
		auto iter = u_map.find(Pre_sum[i] - k);
		if (iter != u_map.end())
		{
			count += iter->second;
		}
		if (Pre_sum[i] == k) count += 1;
		u_map[Pre_sum[i]]++;
	}
	return count;
}

int main_sum_k()
{
	vector<int>nums = { -1,2,3,-2,4,5 };
	int k = 5;
	/*int count = Get_count_of_k(nums, k);
	cout << "暴力解法子数组和为k的数有" << count << "个." << endl;*/
	int count = Get_count_of_k_1(nums,k);
	cout << "暴力解法子数组和为k的数有" << count << "个." << endl; 
	return 0;
}