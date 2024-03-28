#include<iostream>
#include<vector>
using namespace std;

//���ص����������㱳�������ķ�����
int Getprocess(vector<int> arr, int bag, int index) {
	// ��������С��0 �� Խ��
	if (bag < 0) return -1;
	//�������±�Խ��ʱ���������ʣ�������պ�Ϊ0��Ϊһ�ַ����������㡣
	if (index == arr.size()) {
		if (bag == 0)
		{
			return 1;// �����������ҵ�һ�ֺϷ����
		}
		else {
			return 0; // ����δ����û�кϷ����
		}
	}
	// ��ʱ��index��װ�뱳����,�������Ϊ����̫�󣬷Ų�������
	int p1 = Getprocess(arr, bag, index + 1);
	// ��ʱ��indexװ�뱳���У����������б仯,������һ��ʱ�̻�����ѡȡ��ʱ�̵�ֵ
	/*int p2 = 0;
	if (bag - arr[index] >= 0)
	{
		p2 = Getprocess(arr, bag - arr[index], index);
	}*/
	// ��������֮��
	//return p1 + p2;
	
	// �ڶ�����ʽ 
	
	//���÷���ֵ�ж�
	int p2 = Getprocess(arr, bag - arr[index], index);
	if (p2 != -1)
	{
		return p1 + p2;
	}
	return p1;
	
}


int change(int amount, vector<int>& coins)
{
	//�������ת��Ϊ����ǡ��װ�����ж����з���
	//���������е�Ԫ�ؿ����ظ�ѡȡ
	int N = coins.size();
	vector<vector<int>>dp(N + 1, vector<int>(amount + 1, 0));
	//��ʼ�����һ��
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

//��ά����
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
		//��֮ǰ��ͬ�������Ǵ�ǰ�������
		//֮ǰ���ǴӺ���ǰ����,֮ǰ����Ԫ�ر�����
		for (int j = coins[i]; j < amount + 1; j++)
		{
			ans[j] += ans[j - coins[i]];
		}
		//���ÿһ�б����Ԫ�صı仯
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
	cout << "�����ݹ�汾:" << Getprocess(ans, amount,0) << endl;
	cout << "��̬�滮�汾:" << change(amount, ans) << endl;
	cout << "��ά��̬�滮�汾:" << change1(amount, ans) << endl;
	return 0;
}