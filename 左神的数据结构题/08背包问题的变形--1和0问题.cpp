#include<iostream>
#include<string>
#include<vector>
using namespace std;

int process(vector<string>& strs, int m, int n,int index);
//获取满足题意的方法数,选出最大的子集合
int ways(vector<string>&strs, int m, int n)
{
	if (strs.size() == 0) return 0;
	return process(strs, m, n,0);
}
//方法实现，index表示下标索引，m和n代表背包容量
int process(vector<string>& strs, int m, int n, int index)
{
	if (index == strs.size()) return 0;
	int zero = 0, one = 0;
	for (char c:strs[index])
	{
		if (c == '0') zero++;
		else one++;
	}
	//本次不选
	int p1 = process(strs, m, n, index + 1);
	//本次要选，但是有条件
	int p2 = 0;
	if (m >= zero && n >= one)
	{
		p2 = process(strs, m - zero, n - one, index + 1) + 1;
	}
	return max(p1, p2);
}
//动态规划版本
int dp(vector<string>& strs, int m, int n)
{
	if (strs.size() == 0) return 0;
	int N = strs.size();
	vector<vector<vector<int>>>dp(N + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
	//初始化
	for (int i = 0; i < m+1; i++)
	{
		for (int j = 0; j < n+1; j++)
		{
			dp[N][i][j] = 0;
		}
	}
	//动态规划部分
	for (int index = N - 1; index >= 0; index--)
	{
		int zero = 0, one = 0;
		for (char c : strs[index])
		{
			if (c == '0')zero++;
			else one++;
		}
		for (int i = 0; i < m+1; i++)
		{
			for (int j = 0; j < n+1; j++)
			{
				int p1 = dp[index + 1][i][j];
				int p2 = 0;
				if (i >= zero && j >= one)
				{
					//这里的1代表价值
					p2 = dp[index + 1][i - zero][j - one] + 1;
				}
				dp[index][i][j] = max(p1, p2);
			}
		}
	}
	return dp[0][m][n];
}

int main08()
{
	vector<string>strs = { "10","0001","1001","1","0","01010101","101" };
	int m = 1 ;
	int n = 1;
	cout << "递归版本满足题意的个数为：" << ways(strs, m, n) << endl;
	cout << "动态规划满足题意的个数为：" << dp(strs, m, n) << endl;
	return 0;
}