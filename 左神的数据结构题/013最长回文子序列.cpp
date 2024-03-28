#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int process(string str, int L, int R);
//获取最长回文子序列长度
int GetMaxStr(string str)
{
	return process(str, 0, str.size() - 1);
}
//考虑L到R的位置
//返回最长长度
int process(string str, int L, int R)
{
	if (L == R) return 1;
	if (L == R - 1)
	{
		return str[L] == str[R] ? 2 : 1;
	}
	//分为四类
	//第一类，回文的数字不在L上，以R结尾
	//int p1 = process(str, L + 1, R);
	//第二类，回文的数字不在R上
	//int p2 = process(str, L, R - 1);
	//既不在L上，也不在R上
	//int p3 = process(str, L + 1, R - 1);
	//即在L上也在R上
	//int p4 = str[L] == str[R] ? 2 + process(str, L + 1, R - 1) : 0;
	//return max(max(p1, p2), max(p3, p4));

	//前三类还可以优化,因为都是取最大值,p1和p2的情形可以覆盖p3
	//第一类，回文的数字不在L上，以R结尾
	int p1 = process(str, L + 1, R);
	//第二类，回文的数字不在R上
	int p2 = process(str, L, R - 1);
	//即在L上也在R上
	int p4 = str[L] == str[R] ? 2 + process(str, L + 1, R - 1) : 0;
	return max(max(p1, p2), p4);
}
//动态规划版本
//因为暴力递归中包含两个参数,所以是一个二维表描述
int longestPalindromeSubseq(string str)
{
	int N = str.size();
	//首先将数组的所有元素初始化为0
	vector<vector<int>>dp(N, vector<int>(N, 0));
	//当L > R时候,是不成立的，所以要初始化和不初始化都不影响表格的内容
	//现在填写对角线上的内容
	dp[N - 1][N - 1] = 1;
	for (int i = 0; i < N-1; i++)
	{
		dp[i][i] = 1;
		dp[i][i + 1] = str[i] == str[i + 1] ? 2 : 1;
	}
	//其他位置的填法
	for (int i = N - 3; i >= 0; i--)
	{
		for (int j = i + 2; j < N; j++)
		{
			if (str[i] == str[j])
			{
				dp[i][j] = dp[i + 1][j - 1] + 2;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return dp[0][N - 1];
}

int main013()
{
	string str = "GSFsadg";
	cout << "暴力递归版本: " << GetMaxStr(str) << endl;
	cout << "动态规划版本: " << longestPalindromeSubseq(str) << endl;
	return 0;
}