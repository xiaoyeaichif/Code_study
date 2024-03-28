#include<iostream>
#include<string>
using namespace std;


//使用字符串的形式解答
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

//使用除法的性质实现判断是否回文
bool Get_useNumber_huiwen(int n )
{
	int ans = 0;
	int a = n;
	int b;
	while (a > 0)
	{
		b = a % 10;
		//b一定要在a的前面,否则会造成操作过a之后又操作a
		a = a / 10;
		ans = ans * 10 + b;
	}
	return ans == n;
}


//主函数实现部分
int main_huiwen()
{
	int n = -12521;
	bool ans1 = Get_huiwen(n);
	bool ans2 = Get_useNumber_huiwen(n);
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
}