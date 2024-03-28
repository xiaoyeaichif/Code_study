#include<iostream>
#include<vector>
using namespace std;

//���ڶ�̬�滮��ʵ��
int way3(int N, int start, int aim, int K)
{
	if (N < 2 || start <1 || start >N || aim < 1 || aim>N || K < 1)
	{
		return -1;
	}
	vector<vector<int>>dp(N + 1, vector<int>(K + 1));
	//��ʼ�����̵�0��
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
	//��ʼ����0�У�start = 0 
	for (int j = 0; j < K+1; j++)
	{
		dp[0][j] = 0;
	}
	for (int rest = 1; rest <= K; rest++)
	{
		dp[1][rest] = dp[2][rest - 1];
		//������2��ʼ��N-1
		for (int cur = 2; cur < N; cur++)
		{
			dp[cur][rest] = dp[cur - 1][rest - 1] + dp[cur + 1][rest - 1];
		}
		//�����ٵ�N����
		dp[N][rest] = dp[N - 1][rest - 1];
	}
	return dp[start][K];
}

int main03()
{
	cout << way3(5, 2, 4, 4);
	return 0;
}

	
