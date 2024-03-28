#include<iostream>
#include<vector>
using namespace std;

long long maximumTripletValue(vector<int>& nums) {
    //增加一个前缀数组和后缀数组即可
    vector<int>qian_(nums.size());
    vector<int>hou_(nums.size());
    qian_[0] = nums[0];
    hou_[0] = nums[nums.size() - 1];
    int N = nums.size();
    for (int i = 1; i < N; i++)
    {
        qian_[i] = max(nums[i], qian_[i - 1]);
    }
    for (int j = N - 2; j >= 0; j--)
    {
        hou_[j] = max(nums[j], hou_[j + 1]);
    }
    int ans = 0;
    for (int i = 1; i < N - 2; i++)
    {
        ans = max(ans, (qian_[i - 1] - nums[i]) * hou_[i + 1]);
    }
    return ans;

}
int main1003()
{
    vector<int>nums = { 6,11,12,12,7,9,2,11,12,4,19,14,16,8,16 };
    int ans = maximumTripletValue(nums);
    cout << ans;
    return 0;
}