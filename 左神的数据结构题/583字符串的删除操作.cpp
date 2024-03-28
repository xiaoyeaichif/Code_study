#include<iostream>
#include<vector>
#include<string>
using namespace std;

//暴力递归版本
//传入的参数index1和index2分别代表数组的前缀个数
int deleteStr(string str1, string str2, int index1, int index2)
{
	//index1和index2都代表前缀的个数
	//表示str1为空字符串
	if (index1 == 0) return index2;
	//表示str2为空字符串
	if (index2 == 0) return index1;

	//当对应的字符相同时，不需要处理
	//此处的index1 - 1代表下标
	if (str1[index1 - 1] == str2[index2-1])
	{
		return deleteStr(str1, str2, index1 - 1, index2 - 1);
	}
	int p1 = deleteStr(str1, str2, index1, index2 - 1) + 1;
	int p2 = deleteStr(str1, str2, index1-1, index2 ) + 1;
	//两个字符都不同，需要将两个字符都删除
	int p3 = deleteStr(str1, str2, index1 - 1, index2-1) + 2;
	return min(p1, min(p2, p3));
	//return min(p1, p2);
}
//动态规划版本
int dpDeleteStr(string str1, string str2)
{
	int M = str1.size();
	int N = str2.size();
	vector<vector<int>>dp(M + 1, vector<int>(N + 1, 0));
	//初始化部分
	for (int j = 0; j < N+1; j++)
	{
		dp[0][j] = j;
	}
	for (int i = 0; i < M+1; i++)
	{
		dp[i][0] = i;
	}
	//填表部分
	for (int i = 1; i < M+1; i++)
	{
		for (int j = 1; j < N+1; j++)
		{
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1] }) + 1;
			}
		}
	}
	for (int i = 0; i < M + 1; i++)
	{
		for (int j = 0; j < N + 1; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return dp[M][N];
}
//方法2,直接用017最长公共子序列的代码就可以
//要使得两个字符串变成一样的字符串且操作最小，只需要找到两个的最长公共子序列就行
//然后使用字符串的原长度减去最长的公共子序列就是要操作的次数


int main583()
{
	string str1 = "horse";
	string str2 = "ros";
	int M = str1.size();
	int N = str2.size();
	cout << "暴力递归版本:" << deleteStr(str1, str2, M, N)<<endl;
	cout << "动态规划版本:" << dpDeleteStr(str1, str2)<<endl;
	return 0;
}