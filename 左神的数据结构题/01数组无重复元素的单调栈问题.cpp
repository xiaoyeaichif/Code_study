#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main022()
{
	vector<int>nums = { 5, 1, 4, 7, 8, 3, 6,2,9,10,11,0 };
	stack<int>sta;
	vector<vector<int>>res(nums.size(), vector <int>(2));
	for (int i = 0; i < nums.size(); i++)
	{
		//为大压小模型
		while (!sta.empty() && nums[sta.top()] > nums[i])
		{
			int top = sta.top();
			res[top][1] = i;
			sta.pop();
			//左边
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