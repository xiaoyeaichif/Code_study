#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold)
    {
        int ans = 0;
        int N = nums.size();
        for (int i = 0; i < N;)
        {
            if (nums[i] > threshold || nums[i] % 2 != 0)
            {
                i++;
                continue;
            }
            int start = i;
            int r = i + 1;
            int cur = nums[i] % 2;
            while (r < N && nums[r] <= threshold && nums[r] % 2 != cur)
            {
                cur = nums[r]%2;
                r++;
            }
            ans = max(ans, r - start);
            i = r;
        }
        return ans;
    }
};

int main1128()
{
    vector<int>nums = { 4,3,1 };
    Solution s1;
    int max = 4;
    int len = s1.longestAlternatingSubarray(nums,max);
    cout << len << endl;
    return 0;
}