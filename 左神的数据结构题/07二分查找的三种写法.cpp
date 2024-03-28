#include<iostream>
#include<vector>
using namespace std;

//�����������Ŀ��Ԫ��target
//�������ʵ����ʽ
int lower_bounded1(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	//���������û��������Ԫ����������,�򷵻�����ĳ���,Ҳ����nums.size(),����Ҳ����left
	return left;
}

//�����������Ŀ��Ԫ��target
//����ҿ������ʵ����ʽ
int lower_bounded2(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size();
	int mid = 0;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else {
			right = mid ;
		}
	}
	//���������û��������Ԫ����������,�򷵻�����ĳ���,Ҳ����nums.size(),����Ҳ����left
	return left;
}

//�����������Ŀ��Ԫ��target
//���ҿ������ʵ����ʽ
int lower_bounded3(vector<int>& nums, int target)
{
	int left = -1;
	int right = nums.size();
	int mid = 0;
	while (left+1 < right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid] < target)
		{
			left = mid ;
		}
		else {
			right = mid;
		}
	}
	//���������û��������Ԫ����������,�򷵻�����ĳ���,Ҳ����nums.size(),����Ҳ����left
	return left+1;
	//Ҳ����
	// return right;
}

int main032001()
{
	vector<int>res = { 1,2,2,2,3,4,5 };
	int target = 2;
	cout << "ϵͳ��������ʽ:" << *lower_bound(res.begin(),res.end(),target) << endl;
	//STL��������ָ��������±�ָ��,����������һ�������õĸ�ʽ,���Ե�һ��Ԫ�ؾ����±�Ϊ1��Ԫ��2
	cout <<"����ұ��������ʽ:" << lower_bounded1(res, target) << endl;
	cout << "����ҿ��������ʽ:" << lower_bounded2(res, target) << endl;
	cout << "���ҿ��������ʽ:" << lower_bounded3(res, target) << endl;
	return 0;
}