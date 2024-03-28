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

//index,��ʾ��ǰ���ǵ�index��index�ĺ���Ҳ���ɿ���,����ֵΪ����ֵ
int process(vector<int>& weight, vector<int>& value, int index, int bag)
{
	//base case
	//��ֹ��Ч�ļ�ֵ,Ҫ��Խ�����ж�
	if (bag < 0)
	{
		return -1;
	}

	if (index == weight.size()) return 0;
	
	//��ǰ��index������,���Ե���һʱ��ʱ����������û�б仯
	int p1 = process(weight, value, index + 1, bag);

	//���ǵ�ǰ��index,��ʱ�̱���������仯������weight[index];��ֵ����value[index];
	int next = process(weight, value, index + 1, bag - weight[index]);
	int p2 = 0;
	if (next != -1)
	{
		p2 = next + value[index];
	}
	return max(p1, p2);
}

//��̬�滮���֣���ά��������
int dp(vector<int>& weight, vector<int>& value, int bag)
{
	int N = weight.size();
	vector<vector<int>>dp(N + 1, vector<int>(bag + 1));
	//��ʼ��������������һ�п�ʼ,Խ��Ԫ�ض�Ϊ0
	for (int i = 0; i <bag+1; i++)
	{
		dp[N][i] = 0;
	}
	//����ܹ�����
	for (int index = N - 1; index >= 0; index--) {
		//rest����0-bag
		for (int rest = 0; rest < bag+1; rest++)
		{
			//��index�����Ž���Ʒ
			int p1 = dp[index + 1][rest];
			int p2 = 0;
			//��index��������Ʒ,С��0��һ��-1�����ǺŶ��ԣ�-1������û���������˼
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

//һά��������
int dp2(vector<int>& weight, vector<int>& value, int bag)
{
	vector<int>dp2(bag + 1, 0);
	//���е�Ԫ�ز��ᱻ����
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
	cout << "�������������: ";
	if (result != -1) {
		cout << "Max Value: " << result << endl;
	}
	else {
		cout << "Invalid Input" << endl;
	}
	cout << "��̬�滮1�����: "<<endl;
	cout << dp(weight, value, bag)<<endl;
	cout << "��̬�滮2�����: " ;
	cout << dp2(weight, value, bag);
	
	//dp(weight, value, bag);
	return 0;
}