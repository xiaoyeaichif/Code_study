#include<iostream>
#include<vector>
using namespace std;

//�����ݵ�ʵ��
//��ȡx��n�η�
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
		//����,�൱�ڳ���2
		n >>= 1;
	}
	return ans;
}

//�����Ӳ���
//���ӵĴ�С����Ϊ2
int Quick_jianSZ(int bamboo)
{
	if (bamboo == 2) return 1;
	if (bamboo == 3)return 2;
	//res����������
	//res=1,2,3
	int res = bamboo % 3;
	int mod = 1e9 + 7;
	//res == 0,Ҳ����������3,���ֵ����3��n�η�
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
//��������ʵ��
int main022002()
{
	int boom = 20;
	int ans = Quick_jianSZ(boom);
	cout << ans;
	return 0;

}