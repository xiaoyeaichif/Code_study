#include<iostream>
#include<vector>
using namespace std;

int Get_min_digit1(vector<int>& ans)
{
	//���ֲ��ҵĵ�һ��д��
	int left = 0;
	int right = ans.size() - 2;
	int mid = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		//��ɫ
		//mid-right����Ⱦ����ɫ
		//��ɫ������Сֵ�����Ҳ�Ԫ��
		if (ans[mid] < ans.back())
		{
			right = mid - 1;
		}
		//��ɫ
		// 0-mid����ȾΪ��ɫ
		//ans[mid] > ans.back()
		else {
			left = mid + 1 ;
		}
	}
	return ans[left];
}

//������
int Get_min_digit2(vector<int>& nums)
{
	int left = 0;
	int right = nums.size() - 1;
	int mid = 0;
	while (nums[left] >= nums[right])
	{
		if (right - left == 1)return nums[right];
		mid = left + (right - left) / 2;
		if (nums[mid] >= nums[left])
		{
			left = mid;
		}
		else if (nums[right] >= nums[mid])
		{
			right = mid;
		}
	}
	return nums[mid];
}


int main0320()
{
	vector<int>ans = { 4,5,6,7,0,1,2 };
	cout << "ʹ�ö��ֲ��ҵĵ�һ��д�����Ĵ𰸣�" << Get_min_digit1(ans) << endl;
	cout << "ʹ�ö��ֲ��ҵĵڶ���д�����Ĵ𰸣�" << Get_min_digit2(ans) << endl;
	return 0;
}