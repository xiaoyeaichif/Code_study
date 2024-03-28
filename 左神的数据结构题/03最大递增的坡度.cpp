#include<iostream>
#include<vector>
#include<stack>
using namespace std;


class Solution {
public:
    int maxWidthRamp(vector<int>& nums)
    {
        stack<int>sta;
        sta.push(0);
        int ans = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[sta.top()] > nums[i])
            {
                sta.push(i);
            }
        }
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            while (!sta.empty() && nums[i] >= nums[sta.top()])
            {
                ans = max(ans, i - sta.top());
                sta.pop();
            }
        }
        return ans;
    }
};

//主函数实现部分
int main24()
{
    Solution s1;
    vector<int>nums = { 4,2,3,6,4,7,63,1,123,9,13,894,23,123,96,31,3 };
    int ans = s1.maxWidthRamp(nums);
    cout << "最大上升坡度为：" << ans;
    return 0;
}