#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int process(string s1, string s2, int M, int N);
int getmax(string str1, string str2)
{
	return process(str1, str2, str1.size() - 1, str2.size() - 1);
}


//样本对应模型
//获取两个字符串最长的公共子序列
int process(string s1, string s2, int M, int N)
{
	if (M == 0 && N == 0)
	{
		return s1[M] == s2[N] ? 1 : 0;
	}
	else if (M == 0)
	{
		//此时N != 0
		if (s1[M] == s2[N])
		{
			return 1;
		}
		else
		{
			return process(s1, s2, M, N - 1);
		}
	}
	else if (N == 0)
	{
		//此刻M != 0
		if (s1[M] == s2[N])
		{
			return 1;
		}
		else
		{
			return process(s1, s2, M-1, N);
		}
	}
	else {
		//N != 0&& M != 0
		//分为几种情形
		//1：M 与 N两处的元素相同，M与N处不相同;
		//M与N处不相同时，两种情形
		//不考虑M,可能考虑N
		int  p1 = process(s1, s2, M - 1, N);
		//可能考虑M ,不考虑N
		int p2 = process(s1, s2, M, N - 1);
		//考虑M和N
		int p3 = s1[M] == s2[N] ? 1 + process(s1, s2, M - 1 , N - 1) : 0;
		return max(p1, max(p2, p3));
	}
}

int main14()
{
	string str1 = "f12gfjh75864";
	string str2 = "hfcy1235jf";
	cout << getmax(str1, str2);
	return 0;
}