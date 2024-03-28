#include<iostream>
#include<vector>
using namespace std;

//返回的是需要的最少硬币个数,暴力递归
int Coinprocess(vector<int> arr, int bag, int index) {
	// 背包容量为0，所以不需要硬币就可以满足
	if (bag == 0 ) return 0;
	//当数组下标越界时候,bag != 0,表示找不到这样的硬币个数,所以方法为无穷(这个无穷是一个记号,也可以是个负数)
	//当背包容量小于0时,代表也找不到方法
	if (index == arr.size() || bag < 0) {
		return INT_MAX;
	}
	//当前的硬币没选
	int p1 = Coinprocess(arr, bag, index + 1);
	//选择当前的硬币,下一时刻还可以选这个硬币，此时硬币数+1
	int p2 = Coinprocess(arr, bag - arr[index], index);
	if (p1 != INT_MAX && p2 != INT_MAX)
	{
		return min(p1, p2+1);
	}
	else if (p1 != INT_MAX)
	{
		return p1;
	}
	else if (p2 != INT_MAX)
	{
		return p2+1;
	}
	else {
		return INT_MAX;
	}
}

//记忆化搜索方式，传什么就输出什么
int Coinprocess(vector<int> arr, int bag, int index,vector<vector<int>>& dp) {
	// 背包容量为0，所以不需要硬币就可以满足
	if (bag == 0) return 0;
	//当数组下标越界时候,bag != 0,表示找不到这样的硬币个数,所以方法为无穷(这个无穷是一个记号,也可以是个负数)
	//当背包容量小于0时,代表也找不到方法
	if (index == arr.size() || bag < 0) {
		return INT_MAX;
	}
	if (dp[index][bag] != INT_MAX) return dp[index][bag];
	//当前的硬币没选
	int p1 = Coinprocess(arr, bag, index + 1);
	//选择当前的硬币,下一时刻还可以选这个硬币，此时硬币数+1,要先判断再加1
	int p2 = Coinprocess(arr, bag - arr[index], index);
	if (p1 != INT_MAX && p2 != INT_MAX)
	{
		dp[index][bag] =  min(p1, p2 + 1);
	}
	else if (p1 != INT_MAX)
	{
		dp[index][bag] =  p1;
	}
	else if (p2 != INT_MAX)
	{
		dp[index][bag] = p2 + 1;
	}
	else {
		dp[index][bag] = INT_MAX;
	}
	return dp[index][bag];
}

//动态规划版本
int Coindp(vector<int>& Coin,int amount)
{
	int N = Coin.size();
	vector<vector<int>>dp(N + 1, vector<int>(amount + 1,0));
	//当bag == 0 时应该都是0,也就是第0列元素全为0
	//倒数第一行从第二个数开始初始化
	for (int j = 1; j < amount+1; j++)
	{
		dp[N][j] = INT_MAX;
	}
	//开始从N-1行填表
	for (int index = N - 1; index >= 0; index--)
	{
		for (int rest = 0; rest < amount + 1; rest++)
		{
			dp[index][rest] = dp[index + 1][rest];
			if (rest - Coin[index] >= 0 && dp[index][rest - Coin[index]] != INT_MAX)
			{
				dp[index][rest] = min(dp[index][rest - Coin[index]] + 1, dp[index][rest]);
			}
		}
	}
	for (auto nums : dp)
	{
		for (  auto num : nums)
		{
			cout << num << ' ';
		}
		cout << endl;
	}
	return dp[0][amount] == INT_MAX ? -1 : dp[0][amount];
}

//降维打击部分//空间压缩部分
int Coindp1(vector<int>& Coin, int amount)
{
	int N = Coin.size();
	vector<int>dp(amount + 1, INT_MAX);
	//当bag == 0 时应该都是0,也就是第0列元素全为0
	dp[0] = 0;
	//开始从N-1行填表
	for (int index = N - 1; index >= 0; index--)
	{
		//这里的初始化也可以不用从0开始
		//for(int rest = Coin[index];rest < amount+1;rest++)
		for (int rest = 0; rest < amount + 1; rest++)
		{
			if (rest - Coin[index] >= 0 && dp[rest - Coin[index]] != INT_MAX)
			{
				dp[rest] = min(dp[rest - Coin[index]] + 1, dp[rest]);
			}
		}
	}
	for (auto num : dp)
	{
		cout << num << ' ';
	}
	cout << endl;
	return dp[amount] == INT_MAX ? -1 : dp[amount];
}





int mainCoin1()
{
	vector<int>ans = { 5,2,3,1 };
	int amount = 4;
	int N = ans.size();
	vector<vector<int>>dp(N + 1, vector<int>(amount + 1, INT_MAX));
	cout << "暴力递归版本:" << Coinprocess(ans, amount, 0) << endl;
	cout << "记忆化搜索递归版本:" << Coinprocess(ans, amount, 0,dp) << endl;
	cout << "动态规划递归版本:" << Coindp(ans, amount) << endl;
	cout << "动态规划递归版本:" << Coindp1(ans, amount) << endl;
	return 0;
}