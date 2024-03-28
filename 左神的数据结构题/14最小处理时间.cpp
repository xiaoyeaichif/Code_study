#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks)
    {
        int m = processorTime.size();
        int n = tasks.size();
        vector<int>ans;
        sort(tasks.rbegin(), tasks.rend());
        int count = 1;
        for (int i = 0; i < n / 4 + 1; i++)
        {
            int pre = 0;
            for (int j = count - 1; j < n; j++)
            {
                pre = max(pre, tasks[j]);
                count++;
                if ((count - 1) % 4 == 0)
                {
                    ans.push_back(pre);
                    break;
                }
            }
        }
        sort(processorTime.begin(), processorTime.end());
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            res = max(res, processorTime[i] + ans[i]);
        }
        return res;
    }
};
int main1024()
{
    Solution z1;
    vector<int>processorTime = { 8, 10 };
    vector<int>tasks = { 2, 2, 3, 1, 8, 7, 4, 5 };
    int ans = 0;
    ans = z1.minProcessingTime(processorTime, tasks);
    cout << ans;
    return 0;
}