#include<iostream>
#include<vector>
using namespace std;

//��������
int process2(int x, int y, int rest, int a, int b);
//(x,y)����k����������(a,b)�ķ�����
int Getways(int k,int a,int b)
{
	return process2(0, 0, k, a, b);
}
//x*y = 10*9
int process2(int x, int y, int rest, int a, int b)
{
	//Խ�翼�ǣ���������
	if (x < 0 || x>9 || y < 0 || y>8)
	{
		return 0;
	}
	if (rest == 0)
	{
		if (x == a && y == b)
		{
			return 1;
		}
		return 0;
	}
	int ways = 0;
	int p1 = process2(x + 1, y + 2, rest - 1, a, b);
	int p2 = process2(x + 2, y + 1, rest - 1, a, b);
	int p3 = process2(x + 2, y - 1, rest - 1, a, b);
	int p4 = process2(x + 1, y - 2, rest - 1, a, b);
	int p5 = process2(x - 1, y - 2, rest - 1, a, b);
	int p6 = process2(x - 2, y - 1, rest - 1, a, b);
	int p7 = process2(x - 2, y + 1, rest - 1, a, b);
	int p8 = process2(x - 1, y + 2, rest - 1, a, b);
	ways = p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8;
	return ways;
}

int main11()
{
	int x = 7;
	int y = 7;
	int step = 10;
	cout <<"�����ݹ�ķ�ʽ��"<< Getways(step, x, y)<<endl;
	return 0;
}