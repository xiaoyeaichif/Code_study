#include<iostream>
#include<vector>
using namespace std;

//��������ģ��
//��ȡ���͵��ֵ
//nums[0....i],i�����±�����
int process(vector<int>nums, int i)
{
	if (i == 0)
	{
		return nums[i];
	}
	if (i == 1)
	{
		return max(nums[0], nums[i]);
	}
	//ѡ��ǰ���±�i
	int p1 = 0;
	if(i- 2 >= 0) p1 = nums[i] + process(nums, i - 2);
	//��ѡ��ǰ���±�i
	int p2 = process(nums, i - 1);
	return max(p1, p2);
}

//��̬�滮�汾
int dp(vector<int>nums)
{
	//�߽�
	if (nums.size() == 1) return nums[0];
	//�ɵݹ��֪��ĳ���Ӧ��Ϊi-0+1 = i+1��i��������±�
	int N = nums.size();
	vector<int>ans(N, 0);
	ans[0] = nums[0];
	ans[1] = max(nums[0], nums[1]);
	for (int i = 2; i < N; i++)
	{
		ans[i] = max(ans[i - 1], ans[i - 2] + nums[i]);
	}
	return ans[N - 1];
}

int main020()
{
	vector<int>nums = { 2,7,9,3,1 };
	int size = nums.size() - 1;
	cout << "�ݹ�汾�����ֵ��" << process(nums, size) <<endl ;
	cout << "��̬�滮�汾�����ֵ��" << dp(nums) << endl;
	return 0;
}