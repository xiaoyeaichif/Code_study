#include<iostream>
#include<vector>
#include<string>
using namespace std;

//�����ݹ�汾
//����Ĳ���index1��index2�ֱ���������ǰ׺����
int deleteStr(string str1, string str2, int index1, int index2)
{
	//index1��index2������ǰ׺�ĸ���
	//��ʾstr1Ϊ���ַ���
	if (index1 == 0) return index2;
	//��ʾstr2Ϊ���ַ���
	if (index2 == 0) return index1;

	//����Ӧ���ַ���ͬʱ������Ҫ����
	//�˴���index1 - 1�����±�
	if (str1[index1 - 1] == str2[index2-1])
	{
		return deleteStr(str1, str2, index1 - 1, index2 - 1);
	}
	int p1 = deleteStr(str1, str2, index1, index2 - 1) + 1;
	int p2 = deleteStr(str1, str2, index1-1, index2 ) + 1;
	//�����ַ�����ͬ����Ҫ�������ַ���ɾ��
	int p3 = deleteStr(str1, str2, index1 - 1, index2-1) + 2;
	return min(p1, min(p2, p3));
	//return min(p1, p2);
}
//��̬�滮�汾
int dpDeleteStr(string str1, string str2)
{
	int M = str1.size();
	int N = str2.size();
	vector<vector<int>>dp(M + 1, vector<int>(N + 1, 0));
	//��ʼ������
	for (int j = 0; j < N+1; j++)
	{
		dp[0][j] = j;
	}
	for (int i = 0; i < M+1; i++)
	{
		dp[i][0] = i;
	}
	//�����
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
//����2,ֱ����017����������еĴ���Ϳ���
//Ҫʹ�������ַ������һ�����ַ����Ҳ�����С��ֻ��Ҫ�ҵ�����������������о���
//Ȼ��ʹ���ַ�����ԭ���ȼ�ȥ��Ĺ��������о���Ҫ�����Ĵ���


int main583()
{
	string str1 = "horse";
	string str2 = "ros";
	int M = str1.size();
	int N = str2.size();
	cout << "�����ݹ�汾:" << deleteStr(str1, str2, M, N)<<endl;
	cout << "��̬�滮�汾:" << dpDeleteStr(str1, str2)<<endl;
	return 0;
}