#include<iostream>
#include<vector>
using namespace std;

//返回的是正好满足背包容量的方法数
int Getprocess(vector<int> arr, int bag, int index) {
	// 背包容量小于0 或 越界
	if (bag < 0) return -1;
	//当数组下标越界时候，如果背包剩余容量刚好为0，为一种方法，否则不算。
	if (index == arr.size()) {
		if (bag == 0)
		{
			return 1;// 背包已满，找到一种合法组合
		}
		else {
			return 0; // 背包未满，没有合法组合
		}
	}
	// 此时刻index不装入背包中,可以理解为重量太大，放不进背包
	int p1 = Getprocess(arr, bag, index + 1);
	// 此时刻index装入背包中，背包重量有变化,但是下一个时刻还可以选取本时刻的值
	/*int p2 = 0;
	if (bag - arr[index] >= 0)
	{
		p2 = Getprocess(arr, bag - arr[index], index);
	}*/
	// 返回两者之和
	//return p1 + p2;
	
	// 第二种形式 
	
	//利用返回值判断
	int p2 = Getprocess(arr, bag - arr[index], index);
	if (p2 != -1)
	{
		return p1 + p2;
	}
	return p1;
	
}


int change(int amount, vector<int>& coins)
{
	//问题可以转化为背包恰好装满能有多少中方案
	//另外数组中的元素可以重复选取
	int N = coins.size();
	vector<vector<int>>dp(N + 1, vector<int>(amount + 1, 0));
	//初始化最后一行
	for (int j = 0; j < amount + 1; j++)
	{
		dp[N][j] = j == 0 ? 1 : 0;
	}
	for (int index = N - 1; index >= 0; index--)
	{
		for (int rest = 0; rest < amount + 1; rest++)
		{
			int p1 = dp[index + 1][rest];
			int p2 = 0;
			if (rest - coins[index] >= 0)
			{
				p2 = dp[index][rest - coins[index]];
			}
			dp[index][rest] = p1 + p2;
		}
	}
	for (int i = 0; i < N+1; i++)
	{
		for (int j = 0; j < amount + 1; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return dp[0][amount];
}

//降维处理
int change1(int amount, vector<int>& coins)
{
	int N = coins.size();
	vector<int> ans(amount+1, 0);
	ans[0] = 1;
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < amount + 1; j++)
		{
			if (j - coins[i] >= 0)
			{
				ans[j] += ans[j - coins[i]];
			}
		}
	}*/
	for (int i = N - 1; i >= 0; i--)
	{
		//与之前不同，这里是从前往后遍历
		//之前都是从后往前遍历,之前是怕元素被覆盖
		for (int j = coins[i]; j < amount + 1; j++)
		{
			ans[j] += ans[j - coins[i]];
		}
		//输出每一行表格中元素的变化
		for (auto num : ans)
		{
			cout << num << ' ';
		}
		cout << endl;
	}

	return ans[amount];

}



int mainCoin2()
{
	vector<int>ans = { 5,2,3 ,1};
	int amount = 10;
	cout << "暴力递归版本:" << Getprocess(ans, amount,0) << endl;
	cout << "动态规划版本:" << change(amount, ans) << endl;
	cout << "降维动态规划版本:" << change1(amount, ans) << endl;
	return 0;
}