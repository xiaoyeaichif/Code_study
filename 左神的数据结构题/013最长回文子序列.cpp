#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int process(string str, int L, int R);
//��ȡ����������г���
int GetMaxStr(string str)
{
	return process(str, 0, str.size() - 1);
}
//����L��R��λ��
//���������
int process(string str, int L, int R)
{
	if (L == R) return 1;
	if (L == R - 1)
	{
		return str[L] == str[R] ? 2 : 1;
	}
	//��Ϊ����
	//��һ�࣬���ĵ����ֲ���L�ϣ���R��β
	//int p1 = process(str, L + 1, R);
	//�ڶ��࣬���ĵ����ֲ���R��
	//int p2 = process(str, L, R - 1);
	//�Ȳ���L�ϣ�Ҳ����R��
	//int p3 = process(str, L + 1, R - 1);
	//����L��Ҳ��R��
	//int p4 = str[L] == str[R] ? 2 + process(str, L + 1, R - 1) : 0;
	//return max(max(p1, p2), max(p3, p4));

	//ǰ���໹�����Ż�,��Ϊ����ȡ���ֵ,p1��p2�����ο��Ը���p3
	//��һ�࣬���ĵ����ֲ���L�ϣ���R��β
	int p1 = process(str, L + 1, R);
	//�ڶ��࣬���ĵ����ֲ���R��
	int p2 = process(str, L, R - 1);
	//����L��Ҳ��R��
	int p4 = str[L] == str[R] ? 2 + process(str, L + 1, R - 1) : 0;
	return max(max(p1, p2), p4);
}
//��̬�滮�汾
//��Ϊ�����ݹ��а�����������,������һ����ά������
int longestPalindromeSubseq(string str)
{
	int N = str.size();
	//���Ƚ����������Ԫ�س�ʼ��Ϊ0
	vector<vector<int>>dp(N, vector<int>(N, 0));
	//��L > Rʱ��,�ǲ������ģ�����Ҫ��ʼ���Ͳ���ʼ������Ӱ���������
	//������д�Խ����ϵ�����
	dp[N - 1][N - 1] = 1;
	for (int i = 0; i < N-1; i++)
	{
		dp[i][i] = 1;
		dp[i][i + 1] = str[i] == str[i + 1] ? 2 : 1;
	}
	//����λ�õ��
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
	cout << "�����ݹ�汾: " << GetMaxStr(str) << endl;
	cout << "��̬�滮�汾: " << longestPalindromeSubseq(str) << endl;
	return 0;
}