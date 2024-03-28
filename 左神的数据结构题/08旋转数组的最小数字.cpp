#include<iostream>
#include<vector>
using namespace std;

int Get_min_digit1(vector<int>& ans)
{
	//二分查找的第一种写法
	int left = 0;
	int right = ans.size() - 2;
	int mid = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		//蓝色
		//mid-right都被染成蓝色
		//蓝色代表最小值及其右侧元素
		if (ans[mid] < ans.back())
		{
			right = mid - 1;
		}
		//红色
		// 0-mid都被染为红色
		//ans[mid] > ans.back()
		else {
			left = mid + 1 ;
		}
	}
	return ans[left];
}

//方法二
int Get_min_digit2(vector<int>& nums)
{
	int left = 0;
	int right = nums.size() - 1;
	int mid = 0;
	while (nums[left] >= nums[right])
	{
		if (right - left == 1)return nums[right];
		mid = left + (right - left) / 2;
		if (nums[mid] >= nums[left])
		{
			left = mid;
		}
		else if (nums[right] >= nums[mid])
		{
			right = mid;
		}
	}
	return nums[mid];
}


int main0320()
{
	vector<int>ans = { 4,5,6,7,0,1,2 };
	cout << "使用二分查找的第一种写出来的答案：" << Get_min_digit1(ans) << endl;
	cout << "使用二分查找的第二种写出来的答案：" << Get_min_digit2(ans) << endl;
	return 0;
}