#include<iostream>
#include<vector>
using namespace std;

//�����Ҫ���ǹ�Ʊ������Ϳ��Ե�����,Ҳ����ѡ������֮���ĳ������

int maxproift(vector<int>& nums)
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

int main01210()
{
	vector<int>nums = { 7,1,2,3,4,8,3,2,1,5};
	cout << "̰���㷨�Ĵ���:" << maxproift(nums) << endl;
	return 0;
}