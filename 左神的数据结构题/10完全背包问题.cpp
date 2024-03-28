#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//��������
int Process(vector<int>& weight, vector<int>& value, int index, int bag);
//ʵ�ֵ�������
//���ؿ����ظ����뱳�����������Ҳ����ڱ��������ļ�ֵ���ֵ
int GetMAX(vector<int>& weight, vector<int>& value, int bag)
{
	//�߽������ж�
	if (weight.size() != value.size() || weight.size() == 0 || value.size() == 0)
	{
		return 0;
	}
	return Process(weight, value, 0, bag);
}

//������ʵ��
int Process(vector<int>& weight, vector<int>& value, int index, int bag)
{
	if (bag < 0) return -1;
	//Խ�绹û�ҵ������ֵ
	if (index == weight.size()) return 0;
	//indexʱ�̲�ѡȡ������һ���±�ѡ
	int p1 = Process(weight, value, index + 1, bag);
	//indexʱ��ѡȡ����һ��ʱ�̻�����ѡ��ʱ�̵���Ʒ
	int p2 = 0;
	int next = Process(weight, value, index, bag- weight[index]);
	if (next != -1)
	{
		p2 = next + value[index];
	}
	return max(p1, p2);
}

//��̬�滮����
int knapsack(vector<int>& weight, vector<int>& value, int bag) {
	int n = weight.size();

	// ����һ����ά�������洢�м���
	vector<vector<int>> dp(n + 1, vector<int>(bag + 1, 0));

	// �����һ����Ʒ��ʼ����
	for (int index = n - 1; index >= 0; --index) {
		for (int currentBag = 0; currentBag <= bag; ++currentBag) {
			// ��ѡ��ǰ��Ʒ
			int notChooseCurrent = dp[index + 1][currentBag];

			// ѡ��ǰ��Ʒ
			int chooseCurrent = 0;
			if (currentBag >= weight[index]) {
				chooseCurrent = dp[index][currentBag - weight[index]] + value[index];
			}
			dp[index][currentBag] = max(chooseCurrent, notChooseCurrent);
		}
	}
	return dp[0][bag]; // �����ڸ������������µ�����ֵ
}



int main10()
{
	vector<int> weight = { 2, 4, 6 ,1,3};
	vector<int> value = { 11, 20, 30,1,15 };
	int bag = 11;
	cout <<"�����ݹ�Ľ��: "<< GetMAX(weight, value, bag)<<endl;
	cout << "��̬�滮�Ľ��: " << knapsack(weight, value, bag) << endl;
	return 0;
}