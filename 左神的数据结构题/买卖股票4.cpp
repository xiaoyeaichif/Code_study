#include<iostream>
#include<vector>
using namespace std;

//�������������λ�õ��������
int maxproift2(vector<int>& nums)
{
	//ans = 0�������򣬵�����������
	//��һ�������ֻ��0
	int ans = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		//nums[i] - nums[i - 1]������������
		//����ͼ���������ǳ���
		ans += max(0, nums[i] - nums[i - 1]);
	}
	return ans;
}


//����max_k�ܻ�ȡ���������
int Max_profit(int max_k, vector<int>& profit)
{
	int N = profit.size();
	if (N == 0) return 0;
	//���������max_kԶ�������鳤�ȵ�һ�룬��ô�൱�ڿ��Բ���������
	if (max_k > N / 2) return maxproift2(profit);

	vector<vector<vector<int>>>dp(N, vector<vector<int>>(max_k + 1, vector<int>(2, 0)));
	//k == 0ʱ��ĳ�ʼ��
	for (int i = 0; i < N; i++)
	{
		dp[i][0][0] = 0;
		dp[i][0][1] = INT_MIN;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = max_k; j >= 1; j--)
		{
			if (i == 0)
			{
				dp[i][j][0] = 0;
				//ֻ�ܽ�����,������Ҫ����
				dp[i][j][1] = -profit[i];
				//i == 0���������������
				continue;
			}
			dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + profit[i]);
			dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - profit[i]);
		}
	}
	return dp[N - 1][max_k][0];
}
int main1227()
{
	vector<int>nums = { 3,2,6,5,0,3 };
	int k = 2;
	cout << "���������ܻ�ȡ���������Ϊ��" << Max_profit(k, nums) << endl;
	return 0;
}