#include<iostream>
#include<string>
using namespace std;


//ʹ���ַ�������ʽ���
bool Get_huiwen(int n)
{
	string str = to_string(n);
	int i = 0;
	int j = str.size() - 1;
	while (i < j)
	{
		if (str[i] != str[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}

//ʹ�ó���������ʵ���ж��Ƿ����
bool Get_useNumber_huiwen(int n )
{
	int ans = 0;
	int a = n;
	int b;
	while (a > 0)
	{
		b = a % 10;
		//bһ��Ҫ��a��ǰ��,�������ɲ�����a֮���ֲ���a
		a = a / 10;
		ans = ans * 10 + b;
	}
	return ans == n;
}


//������ʵ�ֲ���
int main_huiwen()
{
	int n = -12521;
	bool ans1 = Get_huiwen(n);
	bool ans2 = Get_useNumber_huiwen(n);
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
}