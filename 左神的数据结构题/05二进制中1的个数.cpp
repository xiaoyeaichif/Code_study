#include<iostream>
using namespace std;

//��ȡһ�����ֵĶ����Ʊ����1�ĸ���
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

//ʹ������������ͬ��Ҫ�޸ĵĶ�����λ���ٵĴ���
int ans_Time(int m, int n)
{
	int ans = 0;
	//ʹ���������ȡ��ͬ��������Ӻ�Ľ��,
	//Ȼ��ͳ������������1�ĸ���,������Ҫ�޸ĵĴ���
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