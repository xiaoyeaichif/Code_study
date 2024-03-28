#include<iostream>
#include<vector>
using namespace std;

void Get_sort(vector<int>& nums)
{
	int left = 0;
	int right = nums.size() - 1;
	//���������˼��
	while (left < right)
	{
		//�ҵ���ߵ�һ����Ϊ0����
		while ( left < right&& nums[left] == 0)
		{
			left += 1;
		}
		//�ҵ��ұߵ�һ����Ϊ1����
		while (left < right && nums[right] == 1)
		{
			right -= 1;
		}
		if (left < right)
		{
			swap(nums[left], nums[right]);
			left += 1;
			right -= 1;
		}
	}
}

int main031101()
{
	vector<int>ans = { 1,0,1,0,1,1,0,0,0,1,0,1,0 };
	cout << "δ����֮ǰ��";
	for (int num : ans)
	{
		cout << num<<' ';
	}
	cout << endl;
	Get_sort(ans);
	cout << "����֮��: ";
	for (int num : ans)
	{
		cout << num << ' ';
	}
	cout << endl;
	return 0;
}