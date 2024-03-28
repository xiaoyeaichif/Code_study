#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        //�ر�ע����mid == rightʱ,����Ҫһ�ν���
        //��Ϊnums[mid]��nums[right]�п��ܵ���0
        while (mid <= right)
        {
            if (nums[mid] == 0 )
            {
                swap(nums[left], nums[mid]);
                left += 1;
                mid += 1;
            }
            else if (nums[mid] == 1 )
            {
                mid += 1;
            }
            else if (nums[mid] == 2 )
            {
                swap(nums[mid], nums[right]);
                right -= 1;
            }
        }
    }
};

int main031102()
{
    vector<int>ans = { 1,0,2 ,1,1,1,0,2,1,0,1,0};
    Solution S1;
    S1.sortColors(ans);
    for (int num : ans)
    {
        cout << num << ' ';
    }
    return 0;
}