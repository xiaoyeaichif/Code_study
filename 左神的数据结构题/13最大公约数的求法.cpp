#include<iostream>
using namespace std;

//这个方法不能处理负数
//但是我们可以把负数看成它的相反数
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

//辗转相除法
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

//递归实现
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}



int main022001()
{
	int m = 30;
	int n = 50;
	cout << "最大公约数为:" << Max_gcd(abs(m), abs(n)) << endl;
	cout << "辗转相除法最大公约数为:" << Max_gcd_ZZ(m, n) << endl;
	cout << "递归法最大公约数为:" << gcd(m, n) << endl;
	return 0;
}