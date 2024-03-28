#include<iostream>
#include<vector>
using namespace std;

//要求
//给定正数n,求裂开的方法，要求后面裂开的数都比前面的大
//例如 n = 3;只能裂成1+1+1，1+2，而不能裂成2+1

//递归实现
//pre：代表上一个拆出来的数，rest：表示还需要rest去拆
//返回的是拆解的方法数
int process(int pre, int rest)
{
	if (rest == 0)
	{
		return 1;
	}
	if (pre > rest)
	{
		return 0;
	}
	/*if (pre == rest)
	{
		return 1;
	}*/
	int ways = 0;
	//first表示当前拆出来的数
	for (int first = pre; first <= rest; first++)
	{
		ways += process(first, rest - first);
	}
	return ways;
}

int Getways(int n)
{
	if (n < 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	return process(1, n);
}
//动态规划的实现
int dp1(int n)
{
	if (n < 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	vector<vector<int>>dp(n + 1, vector<int>(n + +1,0));
	//初始化部分，第一列都为1，对角线的位置，根据观察也可以看出来是1
	for (int i = 1; i < n+1; i++)
	{
		dp[i][0] = 1;
		//pre == rest;代表只有一种方法;因为剩下的数不能在分解了，后面的全
		dp[i][i] = 1;
	}
	//填充表格就可以
	for (int pre = n - 1; pre >= 1; pre--)
	{
		for (int rest = pre + 1; rest <= n; rest++)
		{
			int ways = 0;
			for (int first = pre; first <= rest; first++)
			{
				ways += dp[first][rest - first];
			}
			dp[pre][rest] = ways;
		}
	}
	return dp[1][n];
}

//动态规划改进版，这个是由表格依赖关系看出来的,观察表格的作用
int dp2(int n)
{
	if (n < 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	vector<vector<int>>dp(n + 1, vector<int>(n + +1, 0));
	//初始化部分，第一列都为1，对角线的位置，根据观察也可以看出来是1
	for (int i = 1; i < n + 1; i++)
	{
		dp[i][0] = 1;
		//pre == rest;代表只有一种方法;因为剩下的数不能在分解了，后面的全
		dp[i][i] = 1;
	}
	//填充表格就可以
	for (int pre = n - 1; pre >= 1; pre--)
	{
		for (int rest = pre + 1; rest <= n; rest++)
		{
			dp[pre][rest] = dp[pre + 1][rest];
			dp[pre][rest] += dp[pre][rest-pre];
		}
	}
	return dp[1][n];
}












int main19()
{
	int n = 27;
	cout << "递归形式拆分的方法数:" << Getways(n) << endl;
	cout << "动态规划形式拆分的方法数:" << dp1(n) << endl;
	cout << "优化版本动态规划形式拆分的方法数:" << dp2(n) << endl;
	return 0;
}