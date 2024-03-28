#include<iostream>
#include<string>
using namespace std;

//0 - i-1不去过问，已经转化完毕
//i-......再去转化
//返回的是方法数
//1->A,2->B
int process10(string str, int index)
{
	if (str.size() == index)
	{
		return 1;
	}
	//单独是个数字0
	if (str[index] == '0')
	{
		return  0;
	}
	//index所指不是0,可以任意转化。去看下一个字符
	int ways = process10(str, index + 1);
	//还有种就是i和i+1一起转化
	if (index + 1 < str.size() && (str[index] - '0') * 10 + str[index+1] - '0' < 27)
	{
		ways += process10(str, index + 2);
	}
	return ways;
}

int main1031()
{
	string str = "1012356";
	int way = process10(str, 0);
	cout << way << endl;
	return 0;
}