#include<iostream>
#include<vector>
using namespace std;

//基于动态规划的实现
int way3(int N, int start, int aim, int K)
{
	if (N < 2 || start <1 || start >N || aim < 1 || aim>N || K < 1)
	{
		return -1;
	}
	vector<vector<int>>dp(N + 1, vector<int>(K + 1));
	//初始化过程第0列
	for (int i = 0; i < N + 1; i++)
	{
		if (aim == i)
		{
			dp[aim][0] = 1;
		}
		else {
			dp[i][0] = 0;
		}
	}
	//初始化第0行，start = 0 
	for (int j = 0; j < K+1; j++)
	{
		dp[0][j] = 0;
	}
	for (int rest = 1; rest <= K; rest++)
	{
		dp[1][rest] = dp[2][rest - 1];
		//步数从2开始到N-1
		for (int cur = 2; cur < N; cur++)
		{
			dp[cur][rest] = dp[cur - 1][rest - 1] + dp[cur + 1][rest - 1];
		}
		//处理再第N步的
		dp[N][rest] = dp[N - 1][rest - 1];
	}
	return dp[start][K];
}

int main03()
{
	cout << way3(5, 2, 4, 4);
	return 0;
}

	
