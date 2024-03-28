#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int f1(vector<int>& arr, int L, int R);
int g1(vector<int>& arr, int L, int R);
//获取卡牌游戏值的最大值
int GetMaxValue1(vector<int>& arr)
{	
	if (arr.size() == 0) return 0;
	int first = f1(arr, 0, arr.size() - 1);
	int second = g1(arr, 0, arr.size() - 1);
	return max(first, second);
}
//arr[L,R]先手获得最好的分数返回
int f1(vector<int>& arr, int L, int R)
{
	if (L == R)
	{
		return arr[L];
	}
	//L<R
	//第一次取得最左边
	int p1 = arr[L] + g1(arr, L + 1, R);
	//取的最右侧
	int p2 = arr[R] + g1(arr, L, R - 1);
	return max(p1, p2);
}
//后手函数，后手获得最大值返回
int g1(vector<int>& arr, int L, int R)
{
	//第一张牌已经被取走了，后手函数没牌可取
	if (L == R)
	{
		return 0;
	}
	//如果先手函数取的是arr[L],后手函数只能在L+1 --  R中选取
	int p1 = f1(arr, L + 1, R);
	//如果先手函数取的是arr[R],后手函数只能在L -- R-1中选取
	int p2 = f1(arr, L , R-1);
	return min(p1, p2);
}
//动态规划部分 
int GetMaxValue2(vector<int>& arr)
{
	int N = arr.size();
	vector<vector<int>>fmap(N, vector<int>(N));
	vector<vector<int>>gmap(N, vector<int>(N));
	//初始化部分,右下角部分不用管，或者让他们都为0也行
	for (int i = 0; i < N; i++)
	{
		fmap[i][i] = arr[i];
		gmap[i][i] = 0;
	}
	for (int i = 0;  i < N; i++)
	{
		for (int j = 0; j < i; j++) {
			fmap[i][j] = 0;
			gmap[i][j] = 0;
		}
	}
	//主体部分
	//从列开始遍历
	for (int startCol = 1; startCol < N; startCol++)
	{
		int R = startCol;
		int L = 0;
		while (R < N)
		{
			fmap[L][R] = max(arr[L] + gmap[L+1][R],arr[R] + gmap[L][R-1]);
			gmap[L][R] = min(fmap[L+1][R], fmap[L][R-1]);
			L++;
			R++;
		}
	}
	return max(fmap[0][N - 1], gmap[0][N - 1]);
	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << fmap[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << gmap[i][j] << " ";
		}
		cout << endl;
	}*/
}


int main05()
{
	vector<int>arr = { 1,5,2};
	cout << "暴力递归版本: " ;
	cout<<GetMaxValue1(arr);
	cout << endl;
	cout << "动态规划版本：";
	cout << GetMaxValue2(arr);
	GetMaxValue2(arr);
	return 0;
}