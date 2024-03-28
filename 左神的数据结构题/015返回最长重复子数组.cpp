#include <iostream>
#include <vector>
using namespace std;

//以下标i,j为结尾的最长公共子数组
int findLength(vector<int>& nums1, vector<int>& nums2)
{
    int M = nums1.size();
    int N = nums2.size();
    vector<vector<int>>dp(M, vector<int>(N));
    //初始化dp数组,dp[0][0]
    dp[0][0] = nums1[0] == nums2[0] ? 1 : 0;
    //第0行
    int res = 0;
    for (int j = 1; j < N; j++)
    {
        if (nums1[0] == nums2[j])
        {
            res = 1;
            dp[0][j] = 1;
        }
    }
    //第0列
    for (int i = 1; i < M; i++)
    {
        if (nums1[i] == nums2[0])
        {
            dp[i][0] = 1;
            res = 1;
        }
    }
 
    for (int i = 1; i < M; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (nums1[i] == nums2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            //如果两个对应的下标不等,说明以i和j为下标对应的最长子串长度为0
            else {
                dp[i][j] = 0;
            }
            /*int p3 = nums1[i] == nums2[j] ? dp[i - 1][j - 1] + 1 : 0;
            dp[i][j] = p3;
            res = max(res, dp[i][j]);*/
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
    /*return res;*/
}

//暴力递归过程,代码过程
int process_getmax(vector<int>& nums1, vector<int>& nums2, int i, int j)
{
    if (i == 0 && j == 0) return nums1[i] == nums2[j] ? 1 : 0;
    else if (i == 0)
    {
        if (nums1[0] == nums2[j]) return 1;
        else {
            return 0;
        }
    }
    else if (j == 0)
    {
        if (nums1[i] == nums2[0]) return 1;
        else {
            return 0;
        }
    }
    else {
        if (nums1[i] == nums2[j])
        {
            return process_getmax(nums1, nums2, i - 1, j - 1);
        }
        else {
            return 0;
        }
    }
}
int main015()
{
    vector<int>nums1 = { 1, 0, 0, 0, 1 };
    vector<int>nums2 = { 1, 1, 0, 2, 1 };
    cout << findLength(nums1, nums2)<<endl;
    cout << process_getmax(nums1, nums2,nums1.size()-1,nums2.size()-1) << endl;

    return 0;
}