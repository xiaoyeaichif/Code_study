#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//strֻ��������1-9
//���ض�����ת������
int process(string str, int index);
int number(string str)
{
	if ( str.length() == 0 )
	{
		return 0;
	}
	return process(str, 0);
}
//str[0....(index-1)]�������
//str[index...]ȥת���������ж�����ת������
int process(string str, int index)
{
	//�±�Խ�磬ֻ��һ�ַ���
	//ǰ���Ѿ�ת����ϣ����ظ÷���
	if (index == str.size()) return 1;
	//str�м��Ԫ�ز��ܵ���Ϊ'0',˵��֮ǰ�ľ����Ǵ����
	if (str[index] == '0')
	{
		return 0;
	}
	//������str[index]Ӧ��Ϊ1-9
	//������1����index������ת
	int ways = process(str, index + 1);
	//������2����index��index+1����һ��ת��
	//�����п������index+1Խ�磬��������λ�õ����ֳ���27
	if (index + 1 < str.size() && (str[index] - '0') * 10 + str[index + 1] - '0' < 27)
	{
		ways += process(str, index + 2);
	}
	return ways;
}
//��̬�滮д��
int dp(string& str)
{
	//�߽�����
	if (str.size() == 0) return 0;
	//���ڵݹ麯��ֻ��һ���ɱ������ֻ��Ҫһά���鼴��
	int N = str.size();
	//����str[i] == '0',���Ƿ��ص���0
	vector<int>dp(N + 1,0);
	//����if (index == str.size()) return 1;
	dp[N] = 1;
	//���ݹ麯����֪��dp����Ԫ���Ǵ��ұ���������
	for (int index = N - 1; index >= 0; index--)
	{
		if (str[index] != '0')
		{
			int ways = dp[index + 1];
			if (index + 1 < N && (str[index] - '0') * 10 + str[index + 1] - '0' < 27)
			{
				ways += dp[index + 2];
			}
			dp[index] = ways;
		}
	}
	return dp[0];
}


int main07()
{
	string str = "10";
	cout << "�����ݹ�ĳ��ԣ�" <<number(str) << endl;
	cout << "��̬�滮��" << dp(str) << endl;
	return 0;
}