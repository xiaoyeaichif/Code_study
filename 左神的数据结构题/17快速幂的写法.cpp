#include<iostream>
using namespace std;

//log(n)复杂度计算x^n次方
long Quick_M(long x, int n, int mod)
{
	long ans = 1;
	while (n > 0)
	{
		if ((n & 1) == 1)
		{
			ans = (ans * x) % mod;
		}
		x = (x * x) % mod;
		n >>= 1;
	}
	return ans;
}

int main021801()
{
	long x = 10;
	int n = 10;
	int mod = 1000000007;
	cout << (int)Quick_M(x, n, mod);
	return 0;
}