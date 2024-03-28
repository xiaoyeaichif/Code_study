#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Myclass {
public:
	int operator()(int x, int y)
	{
		return x + 3 * y;
	}
};


int mainAccum()
{
	int init = 100;
	vector<int>nums = { 10,20,30 };
	//accumulate有两个版本
	//一个版本需要三个参数，一个版本需要四个参数
	int res = accumulate(nums.begin(),nums.end(),init);
	cout << "累加和为:" << res<<endl;
	//四个参数版本,第四个参数为函数参数
	int res1 = accumulate(nums.begin(), nums.end(),init, Myclass());
	cout << "累加和为:" << res1 << endl;
	return 0;
}