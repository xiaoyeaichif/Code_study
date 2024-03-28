#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//�ҵ�������,��Ԫ��ĺ�Ϊtarget
vector<vector<int>> FourSum(vector<int>& nums, int target)
{
	vector<vector<int>>ans;
	int N = nums.size();
	if (N < 4) return {};
	sort(nums.begin(), nums.end());
	for (int i = 0; i < N; i++)
	{
		
		//ֻҪ���±�i��ʼ�����ִ���target �Ͳ�������������
		if (nums[i] >= 0 && target < 0)
		{
			break;
		}
		//��֦����,������������ǵ���
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}
		for (int j = i+1; j < N; j++)
		{
			//��֦����
			if (nums[i] + nums[j] >=0  &&target < 0)break;
			if (j > i + 1 && nums[j] == nums[j - 1]) continue;
			int left = j + 1;
			int right = N - 1;
			//�����±겻���غϣ�����Ͳ��������Ԫ����
			while (left < right)
			{
				int res = nums[i] + nums[j] +  nums[left] + nums[right];
				if (res == target)
				{
					ans.push_back({ nums[i] ,nums[j],nums[left] ,nums[right] });
					while (right > left && nums[right] == nums[right - 1])
					{
						right--;
					}
					while (right > left && nums[left] == nums[left + 1])
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
	}
	return ans;
}

int main010902()
{
	vector<int>ans = { 0,-1,-1,1,1,2,-4,-1,2 };
	int target = 2;
	vector<vector<int>> nows = FourSum(ans, target);
	for (vector<int>& now : nows)
	{
		for (int i : now)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}