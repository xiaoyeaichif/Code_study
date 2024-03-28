#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class My_Bl {
public:
	void operator()(int i)
	{
		cout << " " << i;
	}
};



void test(int i )
{
	cout << ' ' << i;
}

int main122002()
{
	vector<int>nums = { 1,5,3,6,31,8,64 };
	cout << "范围for循环输出:" ;
	for (int num : nums)
	{
		cout << num << " ";
	}
	cout << endl;
	cout << "for_each遍历形式,参数为普通函数:";
	for_each(nums.begin(), nums.end(), test);
	cout << endl;
	cout << "for_each遍历形式,参数为仿函数:";
	for_each(nums.begin(), nums.end(), My_Bl());
	return 0;
}