#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main03STL()
{
	vector<int>nums = { 1,2,3,4,5,6,9,10};
	//lower_bound，upper_bound返回的是迭代器
	auto low = lower_bound(nums.begin(), nums.end(), 6);
	auto up = upper_bound(nums.begin(), nums.end(), 6);
	cout << *low << endl;
	cout << *up << endl;
	*up = 8;
	for (int num : nums)
	{
		cout << num << " ";
	}
	cout << endl;
	return 0;
}