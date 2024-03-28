#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        //特殊情形
        if (nums.size() == 1) return 0;
        int Curcover = 0;
        int Curend = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            Curcover = max(Curcover, nums[i] + i);
            if (i == Curend)
            {
                count++;
                Curend = Curcover;
                //找到第一个立即返回
                if (Curcover >= nums.size() - 1) break;
            }
        }
        return count;

    }
};

int main1214()
{
    vector<int>nums = { 2,3,1,1,4 };
    int ans = 0;
    Solution s1;
    ans = s1.jump(nums);
    cout << ans;
    return 0;
}