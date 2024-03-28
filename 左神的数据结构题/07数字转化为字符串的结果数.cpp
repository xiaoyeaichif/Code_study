#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//str只包含数字1-9
//返回多少种转化方案
int process(string str, int index);
int number(string str)
{
	if ( str.length() == 0 )
	{
		return 0;
	}
	return process(str, 0);
}
//str[0....(index-1)]无需过问
//str[index...]去转化，返回有多少种转化方法
int process(string str, int index)
{
	//下标越界，只有一种方法
	//前面已经转化完毕，返回该方案
	if (index == str.size()) return 1;
	//str中间的元素不能单独为'0',说明之前的决策是错误的
	if (str[index] == '0')
	{
		return 0;
	}
	//接下来str[index]应该为1-9
	//可能性1，让index处单独转
	int ways = process(str, index + 1);
	//可能性2，让index和index+1合在一起转化
	//但是有考虑如果index+1越界，或者两个位置的数字超过27
	if (index + 1 < str.size() && (str[index] - '0') * 10 + str[index + 1] - '0' < 27)
	{
		ways += process(str, index + 2);
	}
	return ways;
}
//动态规划写法
int dp(string& str)
{
	//边界条件
	if (str.size() == 0) return 0;
	//由于递归函数只有一个可变参数，只需要一维数组即可
	int N = str.size();
	//由于str[i] == '0',我们返回的是0
	vector<int>dp(N + 1,0);
	//由于if (index == str.size()) return 1;
	dp[N] = 1;
	//看递归函数可知，dp数组元素是从右边向左边填的
	for (int index = N - 1; index >= 0; index--)
	{
		if (str[index] != '0')
		{
			int ways = dp[index + 1];
			if (index + 1 < N && (str[index] - '0') * 10 + str[index + 1] - '0' < 27)
			{
				ways += dp[index + 2];
			}
			dp[index] = ways;
		}
	}
	return dp[0];
}


int main07()
{
	string str = "10";
	cout << "暴力递归的尝试：" <<number(str) << endl;
	cout << "动态规划：" << dp(str) << endl;
	return 0;
}