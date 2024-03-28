#include<iostream>
#include<vector>
using namespace std;
int main010502()
{
	vector<int>nums = { 0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0};
	int count = 0; 
	int N = nums.size();
	for (int i = 0; i < N; i++)
	{
		if (i == 0 && nums[i] == 0 && (i + 1) < N && nums[i + 1] == 0)
		{
			nums[i] = 1;
			count++;
		}
		else if (i == N - 1 && nums[i] == 0 && nums[i - 1] == 0)
		{
			nums[i] = 1;
			count++;
		}
		else if (i > 0 && i < N - 1 && nums[i] == 0 && nums[i - 1] == 0 && nums[i + 1] == 0)
		{
			nums[i] = 1;
			count++;
		}
	}
	cout << count << endl;
	return 0;
}