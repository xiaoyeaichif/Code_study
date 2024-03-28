#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

//返回有回文子串的个数
//中心扩散法则,左右指针从中间往外扩
int countPalindromes(string& str1, int left, int right)
{
	int count = 0;
	while (left >= 0 && right < str1.size() && str1[left] == str1[right])
	{
		left--;
		right++;
		count++;
	}
	return count;
}

int countSubstring(string& str1)
{
	int res = 0;
	for (int  i = 0; i < str1.size(); i++)
	{
		//当str1的长度为奇数个时,中心为一个
		res += countPalindromes(str1, i, i);
		//当str1的长度为偶数个时,中心为两个
		res += countPalindromes(str1, i, i + 1);
	}
	return res;
}

//动态规划版本
int DpcountSubstring(string& str1)
{
	int N = str1.size();
	vector<vector<bool>>dp(N, vector<bool>(N, false));
	//初始化
	dp[N - 1][N - 1] = true;
	for (int i = 0; i < N-1; i++)
	{
		dp[i][i] = true;
		dp[i][i + 1] = str1[i] == str1[i + 1] ? true : false;
	}
	//填dp表格
	for (int i = N - 3; i >= 0; i--)
	{
		for (int j = i+2; j < N; j++)
		{
			if (str1[i] == str1[j] &&  j-i<=1 || dp[i + 1][j - 1])
			{
				dp[i][j] = true;
			}
		}
	}
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (dp[i][j]) count++;
			cout << dp[i][j] << " ";
		}cout << endl;
	}
	return count;
	
}

int main0647()
{
	string str1 = "aaaaa";
	cout << "双指针版本回文子串个数为:" << countSubstring(str1) << endl;
	cout << "动态规划版本回文子串个数为:" << DpcountSubstring(str1) << endl;
	return 0;
}