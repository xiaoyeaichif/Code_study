#include<iostream>
#include<vector>
using namespace std;

//Ҫ��
//��������n,���ѿ��ķ�����Ҫ������ѿ���������ǰ��Ĵ�
//���� n = 3;ֻ���ѳ�1+1+1��1+2���������ѳ�2+1

//�ݹ�ʵ��
//pre��������һ�������������rest����ʾ����Ҫrestȥ��
//���ص��ǲ��ķ�����
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
	//first��ʾ��ǰ���������
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
//��̬�滮��ʵ��
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
	//��ʼ�����֣���һ�ж�Ϊ1���Խ��ߵ�λ�ã����ݹ۲�Ҳ���Կ�������1
	for (int i = 1; i < n+1; i++)
	{
		dp[i][0] = 1;
		//pre == rest;����ֻ��һ�ַ���;��Ϊʣ�µ��������ڷֽ��ˣ������ȫ
		dp[i][i] = 1;
	}
	//�����Ϳ���
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

//��̬�滮�Ľ��棬������ɱ��������ϵ��������,�۲��������
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
	//��ʼ�����֣���һ�ж�Ϊ1���Խ��ߵ�λ�ã����ݹ۲�Ҳ���Կ�������1
	for (int i = 1; i < n + 1; i++)
	{
		dp[i][0] = 1;
		//pre == rest;����ֻ��һ�ַ���;��Ϊʣ�µ��������ڷֽ��ˣ������ȫ
		dp[i][i] = 1;
	}
	//�����Ϳ���
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
	cout << "�ݹ���ʽ��ֵķ�����:" << Getways(n) << endl;
	cout << "��̬�滮��ʽ��ֵķ�����:" << dp1(n) << endl;
	cout << "�Ż��汾��̬�滮��ʽ��ֵķ�����:" << dp2(n) << endl;
	return 0;
}