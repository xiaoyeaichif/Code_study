#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//�ҵ�������,��Ԫ��ĺ�Ϊtarget
vector<vector<int>> ThreeSum(vector<int>& nums, int target)
{
	vector<vector<int>>ans;
	int N = nums.size();
	if (N < 3) return {};
	sort(nums.begin(), nums.end());
	for (int i = 0; i < N; i++)
	{
		//���target == 0,����ĵ�һ��Ԫ�ش���0,����Ҫ����
		//ֻҪ���±�i��ʼ�����ִ���target �Ͳ�������������
		if (nums[i] > 0)
		{
			break;
		}
		//��֦����,������������õ���
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}
		int left = i + 1;
		int right = N - 1;
		//�����±겻���غϣ�����Ͳ��������Ԫ����
		while (left < right)
		{
			int res = nums[i] + nums[left] + nums[right];
			if (res == target)
			{
				ans.push_back({ nums[i] ,nums[left] ,nums[right] });
				while (right > left && nums[right] == nums[right - 1])
				{
					right--;
				}
				while (right > left && nums[left] == nums[left+1])
				{
					left++;
				}
				//����Ҫ���ƶ�һ��,����Ϊ���ָ������ظ������һ��Ԫ��
				left++;
				right--;
			}
			else if (res > target)
			{
				right--;
			}
			else {
				left++;
			}
		}
	}
	return ans;
}

int main010901()
{
	vector<int>ans = { 0,-1,-1,1,1,2,-4,-1,2 };
	int target = 0;
	vector<vector<int>> nows = ThreeSum(ans, target);
	for ( vector<int> &now : nows )
	{
		for (int i : now)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}