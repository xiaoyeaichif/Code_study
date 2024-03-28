#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//声明函数
int Process(vector<int>& weight, vector<int>& value, int index, int bag);
//实现的主函数
//返回可以重复放入背包的重量，且不大于背包容量的价值最大值
int GetMAX(vector<int>& weight, vector<int>& value, int bag)
{
	//边界条件判断
	if (weight.size() != value.size() || weight.size() == 0 || value.size() == 0)
	{
		return 0;
	}
	return Process(weight, value, 0, bag);
}

//函数的实现
int Process(vector<int>& weight, vector<int>& value, int index, int bag)
{
	if (bag < 0) return -1;
	//越界还没找到满意的值
	if (index == weight.size()) return 0;
	//index时刻不选取，从下一个下标选
	int p1 = Process(weight, value, index + 1, bag);
	//index时刻选取，下一个时刻还可以选本时刻的物品
	int p2 = 0;
	int next = Process(weight, value, index, bag- weight[index]);
	if (next != -1)
	{
		p2 = next + value[index];
	}
	return max(p1, p2);
}

//动态规划部分
int knapsack(vector<int>& weight, vector<int>& value, int bag) {
	int n = weight.size();

	// 创建一个二维数组来存储中间结果
	vector<vector<int>> dp(n + 1, vector<int>(bag + 1, 0));

	// 从最后一个物品开始迭代
	for (int index = n - 1; index >= 0; --index) {
		for (int currentBag = 0; currentBag <= bag; ++currentBag) {
			// 不选择当前物品
			int notChooseCurrent = dp[index + 1][currentBag];

			// 选择当前物品
			int chooseCurrent = 0;
			if (currentBag >= weight[index]) {
				chooseCurrent = dp[index][currentBag - weight[index]] + value[index];
			}
			dp[index][currentBag] = max(chooseCurrent, notChooseCurrent);
		}
	}
	return dp[0][bag]; // 返回在给定背包容量下的最大价值
}



int main10()
{
	vector<int> weight = { 2, 4, 6 ,1,3};
	vector<int> value = { 11, 20, 30,1,15 };
	int bag = 11;
	cout <<"暴力递归的结果: "<< GetMAX(weight, value, bag)<<endl;
	cout << "动态规划的结果: " << knapsack(weight, value, bag) << endl;
	return 0;
}