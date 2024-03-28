#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        for (int i = 0; i < nums.size()-2; i++)
        {
            for (int j = i + 1; j < nums.size()-1; j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    long long res =(long long )(nums[i] - nums[j]) * nums[k];
                    ans = max(ans, res);
                }
            }
        }
        return ans;

    }
};

int main01001()
{
    Solution s2;
    vector<int>nums = { 6,11,12,12,7,9,2,11,12,4,19,14,16,8,16 };
    long long ans = s2.maximumTripletValue(nums);
    cout << ans;
    return 0;
}