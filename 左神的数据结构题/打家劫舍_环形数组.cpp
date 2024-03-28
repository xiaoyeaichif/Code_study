#include<iostream>
#include<vector>
using namespace std;
int robRange(vector<int>& nums, int start, int end);

//��������ģ��
//��ȡ���͵��ֵ
//nums[0....i],i�����±�����
// 
//int process(vector<int>nums, int i)
//{
//	if (i == 0)
//	{
//		return nums[i];
//	}
//	if (i == 1)
//	{
//		return max(nums[0], nums[i]);
//	}
//	//ѡ��ǰ���±�i
//	int p1 = 0;
//	if (i - 2 >= 0) p1 = nums[i] + process(nums, i - 2);
//	//��ѡ��ǰ���±�i
//	int p2 = process(nums, i - 1);
//	return max(p1, p2);
//}

//��̬�滮�汾
int rob(vector<int>& nums) {
    if (nums.size() == 0 ) return 0;
    if (nums.size() == 1) return nums[0];
    int result1 = robRange(nums, 0, nums.size() - 2); // �����
    int result2 = robRange(nums, 1, nums.size() - 1); // �����
    return max(result1, result2);
}
// 198.��ҽ�����߼�
int robRange(vector<int>& nums, int start, int end) {
    if (end == start) return nums[start];
    vector<int> dp(nums.size());
    dp[start] = nums[start];
    dp[start + 1] = max(nums[start], nums[start + 1]);
    for (int i = start + 2; i <= end; i++) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[end];
}




int main1219()
{
	vector<int>nums = { 2,7,5,6,6,3,2,1,5};
	int size = nums.size() - 1;
	cout << "��̬�滮�汾�����ֵ��" << rob(nums) << endl;
	return 0;
}