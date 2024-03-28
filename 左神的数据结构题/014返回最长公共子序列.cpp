#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int process(string s1, string s2, int M, int N);
int getmax(string str1, string str2)
{
	return process(str1, str2, str1.size() - 1, str2.size() - 1);
}


//������Ӧģ��
//��ȡ�����ַ�����Ĺ���������
int process(string s1, string s2, int M, int N)
{
	if (M == 0 && N == 0)
	{
		return s1[M] == s2[N] ? 1 : 0;
	}
	else if (M == 0)
	{
		//��ʱN != 0
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
		//�˿�M != 0
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
		//��Ϊ��������
		//1��M �� N������Ԫ����ͬ��M��N������ͬ;
		//M��N������ͬʱ����������
		//������M,���ܿ���N
		int  p1 = process(s1, s2, M - 1, N);
		//���ܿ���M ,������N
		int p2 = process(s1, s2, M, N - 1);
		//����M��N
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