#include<iostream>
#include<string>
#include<vector>
using namespace std;

//����i,j���������ַ�����ǰ׺����
int differ_(string str1, string str2, int i, int j)
{
	//���str1�ĳ���С��str2�ĳ��ȣ�str1�������в����ܳ���str2
	if (str1.size() < str2.size()) return 0;
	
	//�������ǿ��ַ�,����str1����������str2�г��ֵĸ���Ϊ1
	if (i == 0 && j == 0) return 1;
	//��i==0ʱ����str1��һ�����ַ�,������t�г��ֵĸ���Ϊ0
	if (i == 0) return 0;
	//��j == 1ʱ������str2Ϊһ�����ַ�,str1��������ֻ��һ�����ַ�����ƥ��
	if (j == 0) return 1;

	if (str1[i - 1] == str2[j - 1])
	{
		//����bagg��bag
		return differ_(str1, str2, i - 1, j - 1) + differ_(str1, str2, i - 1, j);
	}
	//����bagx��bag
	return differ_(str1, str2, i - 1, j);
}


//��̬�滮�汾
int dp_differ_(string str1, string str2)
{
	//���str1�ĳ���С��str2�ĳ��ȣ�str1�������в����ܳ���str2
	int M = str1.size(), N = str2.size();
	if ( M < N ) return 0;
	vector<vector<int>>dp(M + 1, vector<int>(N + 1, 0));
	dp[0][0] = 1;
	//��ʼ��
	for (int j = 1; j < N+1; j++)
	{
		dp[0][j] = 0;
	}
	for (int i = 1; i < M+1; i++)
	{
		dp[i][0] = 1;
	}
	for (int  i = 1; i < M+1; i++)
	{
		for (int  j = 1; j < N+1; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
			else{
				dp[i][j] = dp[i - 1][j];
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


int main115()
{
	string str1 = "rabbbit";
	string str2 = "rabbit";
	int M = str1.size();
	int N = str2.size();
	cout << "�����ݹ�汾:" << differ_(str1, str2, M, N) << endl;
	cout << "��̬�滮ʵ�֣�" << dp_differ_(str1, str2) << endl;
	return 0;
}