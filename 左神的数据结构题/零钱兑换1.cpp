#include<iostream>
#include<vector>
using namespace std;

//���ص�����Ҫ������Ӳ�Ҹ���,�����ݹ�
int Coinprocess(vector<int> arr, int bag, int index) {
	// ��������Ϊ0�����Բ���ҪӲ�ҾͿ�������
	if (bag == 0 ) return 0;
	//�������±�Խ��ʱ��,bag != 0,��ʾ�Ҳ���������Ӳ�Ҹ���,���Է���Ϊ����(���������һ���Ǻ�,Ҳ�����Ǹ�����)
	//����������С��0ʱ,����Ҳ�Ҳ�������
	if (index == arr.size() || bag < 0) {
		return INT_MAX;
	}
	//��ǰ��Ӳ��ûѡ
	int p1 = Coinprocess(arr, bag, index + 1);
	//ѡ��ǰ��Ӳ��,��һʱ�̻�����ѡ���Ӳ�ң���ʱӲ����+1
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

//���仯������ʽ����ʲô�����ʲô
int Coinprocess(vector<int> arr, int bag, int index,vector<vector<int>>& dp) {
	// ��������Ϊ0�����Բ���ҪӲ�ҾͿ�������
	if (bag == 0) return 0;
	//�������±�Խ��ʱ��,bag != 0,��ʾ�Ҳ���������Ӳ�Ҹ���,���Է���Ϊ����(���������һ���Ǻ�,Ҳ�����Ǹ�����)
	//����������С��0ʱ,����Ҳ�Ҳ�������
	if (index == arr.size() || bag < 0) {
		return INT_MAX;
	}
	if (dp[index][bag] != INT_MAX) return dp[index][bag];
	//��ǰ��Ӳ��ûѡ
	int p1 = Coinprocess(arr, bag, index + 1);
	//ѡ��ǰ��Ӳ��,��һʱ�̻�����ѡ���Ӳ�ң���ʱӲ����+1,Ҫ���ж��ټ�1
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

//��̬�滮�汾
int Coindp(vector<int>& Coin,int amount)
{
	int N = Coin.size();
	vector<vector<int>>dp(N + 1, vector<int>(amount + 1,0));
	//��bag == 0 ʱӦ�ö���0,Ҳ���ǵ�0��Ԫ��ȫΪ0
	//������һ�дӵڶ�������ʼ��ʼ��
	for (int j = 1; j < amount+1; j++)
	{
		dp[N][j] = INT_MAX;
	}
	//��ʼ��N-1�����
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

//��ά�������//�ռ�ѹ������
int Coindp1(vector<int>& Coin, int amount)
{
	int N = Coin.size();
	vector<int>dp(amount + 1, INT_MAX);
	//��bag == 0 ʱӦ�ö���0,Ҳ���ǵ�0��Ԫ��ȫΪ0
	dp[0] = 0;
	//��ʼ��N-1�����
	for (int index = N - 1; index >= 0; index--)
	{
		//����ĳ�ʼ��Ҳ���Բ��ô�0��ʼ
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
	cout << "�����ݹ�汾:" << Coinprocess(ans, amount, 0) << endl;
	cout << "���仯�����ݹ�汾:" << Coinprocess(ans, amount, 0,dp) << endl;
	cout << "��̬�滮�ݹ�汾:" << Coindp(ans, amount) << endl;
	cout << "��̬�滮�ݹ�汾:" << Coindp1(ans, amount) << endl;
	return 0;
}