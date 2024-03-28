#include<iostream>
using namespace std;

//����������ܴ�����
//�������ǿ��԰Ѹ������������෴��
int Max_gcd(int m, int n)
{
	int gcd = 1;
	for(int i = 1; i <= m && i <= n; i++)
	{
		if (m % i == 0 && n % i == 0)
		{
			gcd = i;
		}
	}
	return gcd;
}

//շת�����
int Max_gcd_ZZ(int m, int n)
{
	int a = m;
	int b = n;
	int t;
	while (b != 0)
	{
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

//�ݹ�ʵ��
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}



int main022001()
{
	int m = 30;
	int n = 50;
	cout << "���Լ��Ϊ:" << Max_gcd(abs(m), abs(n)) << endl;
	cout << "շת��������Լ��Ϊ:" << Max_gcd_ZZ(m, n) << endl;
	cout << "�ݹ鷨���Լ��Ϊ:" << gcd(m, n) << endl;
	return 0;
}