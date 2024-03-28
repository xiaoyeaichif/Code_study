#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums)
    {
        if (nums.size() <= 1) return nums.size();
        //最长递增子序列的变化数组
        int N = nums.size();
        vector<int>dp(N, 1);
        vector<int>count(N, 1);
        int maxtarget = 0;
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if (dp[i] == dp[j] + 1)
                    {
                        count[i] += count[j];
                    }
                }
                if (dp[i] > maxtarget) maxtarget = dp[i];
            }
        }
        int res = 0;
        for (int i = 0; i < N; i++)
        {
            if (dp[i] == maxtarget) res += count[i];
            cout << count[i] << " ";
        }
        cout << endl;
        return res;
    }
};

int main020201()
{
    vector<int>nums = { 1,3,5,4,7 };
    Solution s1;
    cout << s1.findNumberOfLIS(nums) << endl;
    return 0;

}