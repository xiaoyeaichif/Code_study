#include<iostream>
#include<vector>
using namespace std;

void Get_sort(vector<int>& nums)
{
	int left = 0;
	int right = nums.size() - 1;
	//快速排序的思想
	while (left < right)
	{
		//找到左边第一个不为0的数
		while ( left < right&& nums[left] == 0)
		{
			left += 1;
		}
		//找到右边第一个不为1的数
		while (left < right && nums[right] == 1)
		{
			right -= 1;
		}
		if (left < right)
		{
			swap(nums[left], nums[right]);
			left += 1;
			right -= 1;
		}
	}
}

int main031101()
{
	vector<int>ans = { 1,0,1,0,1,1,0,0,0,1,0,1,0 };
	cout << "未操作之前：";
	for (int num : ans)
	{
		cout << num<<' ';
	}
	cout << endl;
	Get_sort(ans);
	cout << "操作之后: ";
	for (int num : ans)
	{
		cout << num << ' ';
	}
	cout << endl;
	return 0;
}