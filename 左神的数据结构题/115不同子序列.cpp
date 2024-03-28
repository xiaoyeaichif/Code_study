#include<iostream>
#include<string>
#include<vector>
using namespace std;

//设置i,j代表两个字符串的前缀长度
int differ_(string str1, string str2, int i, int j)
{
	//如果str1的长度小于str2的长度，str1的子序列不可能出现str2
	if (str1.size() < str2.size()) return 0;
	
	//两个都是空字符,所以str1的子序列在str2中出现的个数为1
	if (i == 0 && j == 0) return 1;
	//当i==0时代表str1是一个空字符,所以在t中出现的个数为0
	if (i == 0) return 0;
	//当j == 1时，代表str2为一个空字符,str1的子序列只有一个空字符和它匹配
	if (j == 0) return 1;

	if (str1[i - 1] == str2[j - 1])
	{
		//例如bagg和bag
		return differ_(str1, str2, i - 1, j - 1) + differ_(str1, str2, i - 1, j);
	}
	//例如bagx和bag
	return differ_(str1, str2, i - 1, j);
}


//动态规划版本
int dp_differ_(string str1, string str2)
{
	//如果str1的长度小于str2的长度，str1的子序列不可能出现str2
	int M = str1.size(), N = str2.size();
	if ( M < N ) return 0;
	vector<vector<int>>dp(M + 1, vector<int>(N + 1, 0));
	dp[0][0] = 1;
	//初始化
	for (int j = 1; j < N+1; j++)
	{
		dp[0][j] = 0;
	}
	for (int i = 1; i < M+1; i++)
	{
		dp[i][0] = 1;
	}
	for (int  i = 1; i < M+1; i++)
	{
		for (int  j = 1; j < N+1; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
			else{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	//查看数组中的每个元素
	for (auto num : dp)
	{
		for (auto ans : num)
		{
			cout << ans << " ";
		}
		cout << endl;
	}
	return dp[M][N];
}


int main115()
{
	string str1 = "rabbbit";
	string str2 = "rabbit";
	int M = str1.size();
	int N = str2.size();
	cout << "暴力递归版本:" << differ_(str1, str2, M, N) << endl;
	cout << "动态规划实现：" << dp_differ_(str1, str2) << endl;
	return 0;
}