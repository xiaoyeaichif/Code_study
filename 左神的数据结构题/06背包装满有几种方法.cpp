#include<iostream>
using namespace std;
#include<vector>


int process(vector<int>arr, int bag, int index);
int Solve(vector<int>arr, int bag)
{
	return process(arr, bag, 0);
}

//返回的是方法数目,index表示的是下标
int process(vector<int> arr, int bag, int index) {
	// 背包容量小于0 或 越界
	if (bag < 0 ) return 0;
	//当数组下标越界时候，如果背包剩余容量刚好为0，为一种方法，否则不算。
	if (index == arr.size()) {
		if (bag == 0)
		{
			return 1;// 背包已满，找到一种合法组合
		}
		else {
			return 0; // 背包未满，没有合法组合
		}
		//return bag == 0 ? 1 : 0;
	}
	
	// 此时刻index不装入背包中,可以理解为重量太大，放不进背包
	int p1 = process(arr, bag, index + 1);
	// 此时刻index装入背包中，背包重量有变化
	int p2 = process(arr, bag - arr[index], index + 1);

	// 返回两者之和
	return p1 + p2;
}



//递归版本
int dp(vector<int>arr, int bag)
{
	int N  = arr.size();
	vector<vector<int>>dp(N + 1, vector<int>(bag + 1));
	//初始化
	for (int i = 0; i < bag + 1; i++)
	{
		dp[N][i] = (i == 0)?1:0;
	}
	//如果考虑背包为0也是一种合法的方法，需要这段代码，否则可有可无，
	//因为会被覆盖掉
	for (int i = 0; i < N + 1; i++)
	{
		dp[i][0] = 1;
	}
	//主体部分的代码
	for (int index = N - 1; index >= 0; index--)
	{
		for (int rest = 0; rest < bag+1; rest++)
		{
			int p1 = dp[index + 1][rest];
			int p2 = 0;
			int next = rest- arr[index] <0?0: dp[index + 1][rest - arr[index]];
			if (next >= 0)
			{
				p2 = next;
			}
			dp[index][rest] = p1 + p2;
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

int main06()
{
	vector<int>arr = { 1,0};
	int bag = 1;
	cout << "递归版本：" << " ";
	cout << Solve(arr, bag) << endl;
	cout << "动态规划版本：" << " " << endl;
	cout << dp(arr, bag);
	//dp(arr, bag);
	return 0;
}