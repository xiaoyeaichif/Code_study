#include<iostream>
#include<vector>
using namespace std;


//此法比较省内存
class Solution {
public:
    //生成一些全局变量使用
    const int static MAX = 100001;
    int deque[MAX] = { 0 };
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        // const int MAX = 100001;
        // vector<int>deque(MAX);
        //start代表初始位置，
        //end代表队列中元素的个数,队列的顶部元素指针为end-1
        int start = 0, end = 0;
        int N = nums.size();
        //先将前k-1个元素的下标索引放进队列中
        for (int i = 0; i < k - 1; i++)
        {
            while (start < end && nums[deque[end - 1]] <= nums[i])
            {
                end--;
            }
            deque[end] = i;
            end++;
        }
        //答案数组的生成
        int  m = N - k + 1;
        vector<int>ans(m);
        //添加元素进队列
        for (int l = 0, r = k - 1; l < m; l++, r++)
        {
            while (start < end && nums[deque[end - 1]] <= nums[r])
            {
                end--;
            }
            deque[end] = r;
            end++;
            //最大值在deque的队头位置
            ans[l] = nums[deque[start]];
            //防止一些元素已经被覆盖
            if (deque[start] == l)
            {
                start++;
            }
        }
        return ans;
    }
};

int main25()
{
    Solution s1;
    int k = 3;
    vector<int>ans;
    vector<int>res = { 1,3,-1,-3,5,6,1,25,45,6,7 };
    ans = s1.maxSlidingWindow(res,k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout <<ans[i] << " ";
    }
    return 0;
}