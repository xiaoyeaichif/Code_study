#include<iostream>
#include<vector>
using namespace std;

//有序数组查找目标元素target
//闭区间的实现形式
int lower_bounded1(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	//如果数组中没有这样的元素满足题意,则返回数组的长度,也就是nums.size(),最终也就是left
	return left;
}

//有序数组查找目标元素target
//左闭右开区间的实现形式
int lower_bounded2(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size();
	int mid = 0;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else {
			right = mid ;
		}
	}
	//如果数组中没有这样的元素满足题意,则返回数组的长度,也就是nums.size(),最终也就是left
	return left;
}

//有序数组查找目标元素target
//左开右开区间的实现形式
int lower_bounded3(vector<int>& nums, int target)
{
	int left = -1;
	int right = nums.size();
	int mid = 0;
	while (left+1 < right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid] < target)
		{
			left = mid ;
		}
		else {
			right = mid;
		}
	}
	//如果数组中没有这样的元素满足题意,则返回数组的长度,也就是nums.size(),最终也就是left
	return left+1;
	//也可以
	// return right;
}

int main032001()
{
	vector<int>res = { 1,2,2,2,3,4,5 };
	int target = 2;
	cout << "系统给定的形式:" << *lower_bound(res.begin(),res.end(),target) << endl;
	//STL给定的是指向数组的下标指针,所以这里有一个解引用的格式,所以第一个元素就是下标为1的元素2
	cout <<"左闭右闭区间的形式:" << lower_bounded1(res, target) << endl;
	cout << "左闭右开区间的形式:" << lower_bounded2(res, target) << endl;
	cout << "左开右开区间的形式:" << lower_bounded3(res, target) << endl;
	return 0;
}