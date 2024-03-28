#include<iostream>
using namespace std;
#include<vector>


int process(vector<int>arr, int bag, int index);
int Solve(vector<int>arr, int bag)
{
	return process(arr, bag, 0);
}

//���ص��Ƿ�����Ŀ,index��ʾ�����±�
int process(vector<int> arr, int bag, int index) {
	// ��������С��0 �� Խ��
	if (bag < 0 ) return 0;
	//�������±�Խ��ʱ���������ʣ�������պ�Ϊ0��Ϊһ�ַ����������㡣
	if (index == arr.size()) {
		if (bag == 0)
		{
			return 1;// �����������ҵ�һ�ֺϷ����
		}
		else {
			return 0; // ����δ����û�кϷ����
		}
		//return bag == 0 ? 1 : 0;
	}
	
	// ��ʱ��index��װ�뱳����,�������Ϊ����̫�󣬷Ų�������
	int p1 = process(arr, bag, index + 1);
	// ��ʱ��indexװ�뱳���У����������б仯
	int p2 = process(arr, bag - arr[index], index + 1);

	// ��������֮��
	return p1 + p2;
}



//�ݹ�汾
int dp(vector<int>arr, int bag)
{
	int N  = arr.size();
	vector<vector<int>>dp(N + 1, vector<int>(bag + 1));
	//��ʼ��
	for (int i = 0; i < bag + 1; i++)
	{
		dp[N][i] = (i == 0)?1:0;
	}
	//������Ǳ���Ϊ0Ҳ��һ�ֺϷ��ķ�������Ҫ��δ��룬������п��ޣ�
	//��Ϊ�ᱻ���ǵ�
	for (int i = 0; i < N + 1; i++)
	{
		dp[i][0] = 1;
	}
	//���岿�ֵĴ���
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
	cout << "�ݹ�汾��" << " ";
	cout << Solve(arr, bag) << endl;
	cout << "��̬�滮�汾��" << " " << endl;
	cout << dp(arr, bag);
	//dp(arr, bag);
	return 0;
}