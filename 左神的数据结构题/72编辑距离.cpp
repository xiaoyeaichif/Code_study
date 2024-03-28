#include<iostream>
#include<string>
#include<vector>
using namespace std;

//i,j代表字符串前缀的长度
//返回的是操作的最小次数
int BJJL_process(string str1, string str2, int index1, int index2)
{
	//index1 == 0代表str1是空字符串,要想使得str1与str2相同,执行删除次数为index2
	if (index1 == 0) return index2;
	//index2 == 0代表str2是空字符串,要想使得str1与str2相同,执行删除次数为index1
	if (index2 == 0) return index1;

	//当index1 - 1 与 index2 - 1下标相同时,不需要操作
	if (str1[index1 - 1] == str2[index2 - 1])
	{
		return BJJL_process(str1, str2, index1 - 1, index2 - 1);
	}
	//对str1进行插入操作,相当于对str2进行删除操作
	int p1 = BJJL_process(str1, str2, index1, index2 - 1) + 1;
	//对str1进行删除操作
	int p2 = BJJL_process(str1, str2, index1 - 1, index2) + 1;
	//对str1进行替换操作
	int p3 = BJJL_process(str1, str2, index1 - 1, index2 - 1) + 1;
	return min(p1, min(p2, p3));
}

//动态规划版本
int DP_bjjl(string str1, string str2)
{
	int M = str1.size();
	int N = str2.size();
	vector<vector<int>>dp(M + 1, vector<int>(N + 1, 0));
	//对表格的初始化
	//dp[0][0] = 0已经初始化过了
	for (int j = 1; j < N + 1; j++)
	{
		dp[0][j] = j;
	}
	for (int i = 1; i < M + 1; i++)
	{
		dp[i][0] = i;
	}
	for (int i = 1; i < M+1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			//两个字符相等,不进行任何操作就是最小的操作，所以和上一个时刻相同
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				//对字符串的删除,插入和替换进行比较
				dp[i][j] = min({ dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1] }) + 1;
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

int main072()
{
	string str1 = "abcd";
	string str2 = "azxcsb";
	int M = str1.size();
	int N = str2.size();
	cout << "暴力递归实现：" <<BJJL_process(str1,str2,M,N) <<endl;
	cout << "动态规划实现：" << DP_bjjl(str1, str2) << endl;
	return 0;
}