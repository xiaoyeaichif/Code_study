#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int process(vector<int>& weight, vector<int>& value, int index, int bag);
int getMaxvalue(vector<int>&weight,vector<int>&value, int bag)
{
	if (weight.size() == 0 || value.size() == 0 || weight.size() != value.size())
	{
		return 0;
	}
	return process(weight, value, 0, bag);
}

//index,表示当前考虑到index，index的后序也都可考虑,返回值为最大价值
int process(vector<int>& weight, vector<int>& value, int index, int bag)
{
	//base case
	//防止无效的价值,要比越界先判断
	if (bag < 0)
	{
		return -1;
	}

	if (index == weight.size()) return 0;
	
	//当前的index不考虑,所以到下一时刻时，背包容量没有变化
	int p1 = process(weight, value, index + 1, bag);

	//考虑当前的index,本时刻背包容量会变化，减少weight[index];价值增加value[index];
	int next = process(weight, value, index + 1, bag - weight[index]);
	int p2 = 0;
	if (next != -1)
	{
		p2 = next + value[index];
	}
	return max(p1, p2);
}

//动态规划部分，二维数组描述
int dp(vector<int>& weight, vector<int>& value, int bag)
{
	int N = weight.size();
	vector<vector<int>>dp(N + 1, vector<int>(bag + 1));
	//初始化，从数组的最后一行开始,越界元素都为0
	for (int i = 0; i <bag+1; i++)
	{
		dp[N][i] = 0;
	}
	//主体架构部分
	for (int index = N - 1; index >= 0; index--) {
		//rest属于0-bag
		for (int rest = 0; rest < bag+1; rest++)
		{
			//在index处不放进物品
			int p1 = dp[index + 1][rest];
			int p2 = 0;
			//在index处放下物品,小于0用一个-1来做记号而言，-1在这里没有特殊的意思
			int next = rest - weight[index] < 0 ? -1 : dp[index + 1][rest - weight[index]];
			if (next != -1)
			{
				p2 = next + value[index];
			}
			dp[index][rest] = max(p1, p2);
		}
	}

	for (int i = 0; i < N+1; i++)
	{
		for (int j = 0; j < bag + 1; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return dp[0][bag];
}

//一维数组描述
int dp2(vector<int>& weight, vector<int>& value, int bag)
{
	vector<int>dp2(bag + 1, 0);
	//表中的元素不会被覆盖
	for (int i = value.size() - 1; i >= 0; i--)
	{
		for (int rest = bag; rest - weight[i] >= 0; rest--)
		{
			dp2[rest] = max(dp2[rest], dp2[rest - weight[i]] + value[i]);
		}
	}
	return dp2[bag];
}



int main04()
{
	vector<int>weight = {1 ,2 ,4 ,7};
	vector<int>value = { 5 ,6 ,3,19 };
	int bag = 10;
	int result = getMaxvalue(weight, value, bag);
	cout << "暴力搜索的输出: ";
	if (result != -1) {
		cout << "Max Value: " << result << endl;
	}
	else {
		cout << "Invalid Input" << endl;
	}
	cout << "动态规划1的输出: "<<endl;
	cout << dp(weight, value, bag)<<endl;
	cout << "动态规划2的输出: " ;
	cout << dp2(weight, value, bag);
	
	//dp(weight, value, bag);
	return 0;
}