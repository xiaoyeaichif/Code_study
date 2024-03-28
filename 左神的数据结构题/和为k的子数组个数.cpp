#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


//�����ⷨ
int Get_count_of_k(vector<int>& nums,int k)
{
	int count = 0;
	int sum;
	int length = nums.size();
	for (int i = 0; i < length; i++)
	{
		sum = nums[i];
		if (sum == k) count += 1;
		for (int j = i+1; j < length; j++)
		{
			sum += nums[j];
			if (sum == k)
			{
				count++;
			}
		}
	}
	return count;
}

//ǰ׺�ͼӹ�ϣ���
int Get_count_of_k_1(vector<int>& nums, int k)
{
	int count = 0;
	int sum = 0;
	int length = nums.size();
	vector<int>Pre_sum(length + 1, 0);
	for (int i = 1; i < length + 1; i++)
	{
		Pre_sum[i] = nums[i - 1] + Pre_sum[i - 1];
	}
	//������ʹ�ù�ϣ���ҵ�����Pre_sum������֮�����k�����־���
	//Ҳ����pre[j] - pre[i] == k
	//��ͻص�������֮�͵����⵱��ȥ��
	unordered_map<int, int>u_map;
	for (int i = 1; i < length+1; i++)
	{
		auto iter = u_map.find(Pre_sum[i] - k);
		if (iter != u_map.end())
		{
			count += iter->second;
		}
		if (Pre_sum[i] == k) count += 1;
		u_map[Pre_sum[i]]++;
	}
	return count;
}

int main_sum_k()
{
	vector<int>nums = { -1,2,3,-2,4,5 };
	int k = 5;
	/*int count = Get_count_of_k(nums, k);
	cout << "�����ⷨ�������Ϊk������" << count << "��." << endl;*/
	int count = Get_count_of_k_1(nums,k);
	cout << "�����ⷨ�������Ϊk������" << count << "��." << endl; 
	return 0;
}