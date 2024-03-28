#include<iostream>
using namespace std;

/*
题目含义，在1-N之间运动，在1位置只能向右移动，在N位置只能向左移动
，处于2-N-1之间的数，左右都可移动，假设机器人初始位置在start，
目标位置为aim，规定机器人只能移动K步，返回机器人从start-aim的方法总和
*/
//要先声明，或者把way1方法写在process1函数后面
int process1(int cur, int rest, int aim, int N);
int way1(int N, int start, int aim, int K)
{
	return process1(start, K, aim, N);
}
//机器人当前所处的位置为cur
//机器人剩余的步数rest
//最终目标为aim
//有哪些位置1-N
int process1(int cur, int rest, int aim, int N)
{
	//如果没有剩余步数且正好处在目标位置时
	if (rest == 0)
	{
		return cur == aim ? 1 : 0;
	}
	//rest>0,还有步数要走,在1位置只能先走到2，再走向目标值
	if (cur == 1)
	{
		return process1(2, rest - 1, aim, N);
	}
	//走在N位置，只能先走到N-1的位置取，在走向aim位置
	if (cur == N)
	{
		return process1(N-1, rest - 1, aim, N);
	}
	//接下来都是在中间的位置走
	return process1(cur - 1, rest - 1, aim, N) +
		process1(cur + 1, rest - 1, aim, N);
}
int main02()
{
	int ans = way1(4, 2, 4, 4);
	cout << ans;
	return 0;
}