#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main23()
{
	vector<int>nums = { 2, 0,1, 0,1,0,2 };
	stack<int>sta;
	vector<vector<int>>res(nums.size(), vector <int>(2));
	for (int i = 0; i < nums.size(); i++)
	{
		//相等时也弹出
		//比无重复元素时多增加一个等号判断
		
		while (!sta.empty() && nums[sta.top()] >= nums[i])
		{
			int top = sta.top();
			res[top][1] = i;
			sta.pop();
			res[top][0] = sta.empty() == true ? -1 : sta.top();
		}
		sta.push(i);
	}
	while (!sta.empty())
	{
		int top = sta.top();
		res[top][1] = -1;
		sta.pop();
		res[top][0] = sta.empty() == true ? -1 : sta.top();
	}
	//要多增加一个修正阶段
	for (int i = nums.size()-2; i >=0 ; i--)
	{
		if (res[i][1] != -1 && nums[i] == nums[res[i][1]]) {
			res[i][1] = res[res[i][1]][1];
		}
	}

	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}