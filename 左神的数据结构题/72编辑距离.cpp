#include<iostream>
#include<string>
#include<vector>
using namespace std;

//i,j�����ַ���ǰ׺�ĳ���
//���ص��ǲ�������С����
int BJJL_process(string str1, string str2, int index1, int index2)
{
	//index1 == 0����str1�ǿ��ַ���,Ҫ��ʹ��str1��str2��ͬ,ִ��ɾ������Ϊindex2
	if (index1 == 0) return index2;
	//index2 == 0����str2�ǿ��ַ���,Ҫ��ʹ��str1��str2��ͬ,ִ��ɾ������Ϊindex1
	if (index2 == 0) return index1;

	//��index1 - 1 �� index2 - 1�±���ͬʱ,����Ҫ����
	if (str1[index1 - 1] == str2[index2 - 1])
	{
		return BJJL_process(str1, str2, index1 - 1, index2 - 1);
	}
	//��str1���в������,�൱�ڶ�str2����ɾ������
	int p1 = BJJL_process(str1, str2, index1, index2 - 1) + 1;
	//��str1����ɾ������
	int p2 = BJJL_process(str1, str2, index1 - 1, index2) + 1;
	//��str1�����滻����
	int p3 = BJJL_process(str1, str2, index1 - 1, index2 - 1) + 1;
	return min(p1, min(p2, p3));
}

//��̬�滮�汾
int DP_bjjl(string str1, string str2)
{
	int M = str1.size();
	int N = str2.size();
	vector<vector<int>>dp(M + 1, vector<int>(N + 1, 0));
	//�Ա��ĳ�ʼ��
	//dp[0][0] = 0�Ѿ���ʼ������
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
			//�����ַ����,�������κβ���������С�Ĳ��������Ժ���һ��ʱ����ͬ
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				//���ַ�����ɾ��,������滻���бȽ�
				dp[i][j] = min({ dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1] }) + 1;
			}
		}
	}
	//�鿴�����е�ÿ��Ԫ��
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
	cout << "�����ݹ�ʵ�֣�" <<BJJL_process(str1,str2,M,N) <<endl;
	cout << "��̬�滮ʵ�֣�" << DP_bjjl(str1, str2) << endl;
	return 0;
}