#include<iostream>
#include<vector>
using namespace std;

//获取数组中所有重复的元素
//数组中的元素范围为1-n
vector<int> findDuplicates(vector<int>& nums)
{
    int size = nums.size();
    if (size < 2) return {};
    vector<int>ans;
    for (int i = 0; i < size; i++)
    {
        if (nums[i] < 1 || nums[i] > size)
        {
            return {};
        }
    }
    for (int num : nums)
    {
        //-1是因为防止数组越界
        // 之前已经把对应索引的元素变成负数了，
        // 这说明 num 重复出现了两次
        if (nums[abs(num) - 1] < 0)
        {
            ans.push_back(abs(num));
        }
        //将数组中的原始都乘以-1
        else {
            nums[abs(num) - 1] *= -1;
        }
    }
    return ans;
}

//主函数
int main0222004()
{
    vector<int> nums = { 2,3,1,2,1,3,5,6,7,8 };
    vector<int> ans = findDuplicates(nums);
    for (int num : ans)
    {
        cout << num << ' ';
    }
    return 0;
}