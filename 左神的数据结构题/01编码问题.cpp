#include<iostream>
#include<string>
using namespace std;

//0 - i-1��ȥ���ʣ��Ѿ�ת�����
//i-......��ȥת��
//���ص��Ƿ�����
//1->A,2->B
int process10(string str, int index)
{
	if (str.size() == index)
	{
		return 1;
	}
	//�����Ǹ�����0
	if (str[index] == '0')
	{
		return  0;
	}
	//index��ָ����0,��������ת����ȥ����һ���ַ�
	int ways = process10(str, index + 1);
	//�����־���i��i+1һ��ת��
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