#include<iostream>
using namespace std;

//获取一个数字的二进制表达中1的个数
int Get_one(int n)
{
	int ans = 0;
	while (n)
	{
		ans += 1;
		n = n & (n - 1);
	}
	return ans;
}

//使得两个数字相同需要修改的二进制位最少的次数
int ans_Time(int m, int n)
{
	int ans = 0;
	//使用异或来获取不同的数字相加后的结果,
	//然后统计异或后数字中1的个数,就是需要修改的次数
	int res = m ^ n;
	ans = Get_one(res);
	return ans;
}


int main022003()
{
	cout << Get_one(5)<<endl;
	cout << ans_Time(10,13) << endl;
	return 0;
}