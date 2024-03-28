#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        //边界条件
        if (s.size() < t.size()) return "";
        vector<int>ans(128, 0);
        int debt = t.size();
        int N = s.size();
        int left = 0;
        //因为要求最小值,用INT_MAX记录
        int len = INT_MAX;
        ///跟踪left的位置
        int start = 0;
        //初始化需要的字符
        for (char c : t)
        {
            ans[c]--;
        }
        for (int right = 0; right < N; right++)
        {
            ans[s[right]]++;
            //只有出现过的元素++后才小于等于0,之前没出现过的++后会大于0
            if (ans[s[right]] <= 0)
            {
                debt--;
            }
            //代表此时的窗口中已经包含t中所有元素
            if (debt == 0)
            {
                while (ans[s[left]] > 0)
                {
                    //把元素吐出窗口,left指针右移
                    ans[s[left]]--;
                    left++;
                }
                //看谁最小
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

int main011229()
{
    string s = "ADOBECODEBANC", t = "ABC";
    Solution Overstr;
    cout << "最小覆盖子串为: " << Overstr.minWindow(s, t) << endl;
    return 0;
}