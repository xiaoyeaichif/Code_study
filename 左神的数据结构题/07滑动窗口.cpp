#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    string minWindow(string s, string t)
    {
        //边界条件判断
        if (s.size() < t.size()) return "";
        vector<int>res(256, 0);
        for (char c : t)
        {
            res[c]--;
        }
        int left = 0;
        int debt = t.size();
        //用来跟踪left
        int start = 0;
        int len = INT_MAX;
        for (int right = 0; right < s.size(); right++)
        {
            res[s[right]]++;
            if (res[s[right]] <= 0)
            {
                debt--;
            }
            //证明窗口内的元素包含代求元素
            if (debt == 0)
            {
                while (res[s[left]] > 0)
                {
                    res[s[left]]--;
                    left++;
                }
                if (right - left + 1 < len)
                {
                    len = right - left + 1;
                    start = left;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

int main28()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string ans;
    Solution Solve_1;
    ans = Solve_1.minWindow(s, t);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}