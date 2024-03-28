#include<iostream>
#include<vector>
using namespace std;

//快速幂的实现
//获取x的n次方
long GetPow(int x, int n, int mod)
{
	long ans = 1;
	while (n > 0)
	{
		if ((n & 1) == 1)
		{
			ans = (ans * x) % mod;
		}
		x = (x * x) % mod;
		//右移,相当于除以2
		n >>= 1;
	}
	return ans;
}

//剪绳子部分
//绳子的大小最少为2
int Quick_jianSZ(int bamboo)
{
	if (bamboo == 2) return 1;
	if (bamboo == 3)return 2;
	//res有三种情形
	//res=1,2,3
	int res = bamboo % 3;
	int mod = 1e9 + 7;
	//res == 0,也就是能整除3,最大值就是3的n次方
	if (res == 0)
	{
		return (int)(GetPow(3, bamboo / 3, mod));
	}
	else if (res == 1)
	{
		long tail = (bamboo - 4) / 3;
		return (int)(4 * GetPow(3, tail, mod));
	}
	else {
		long tail = (bamboo - 2) / 3;
		return (int)(2 * GetPow(3, tail, mod));
	}
}
//主函数的实现
int main022002()
{
	int boom = 20;
	int ans = Quick_jianSZ(boom);
	cout << ans;
	return 0;

}