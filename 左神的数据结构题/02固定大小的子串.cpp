#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s, string t) {
        //边界条件
        if (s.size() > t.size()) return false;
        vector<int>ans(128, 0);
        //和第一题目不一样的地方,核心代码都是一样的
        int debt = s.size();
        int N = t.size();
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
                //看看最小的覆盖字串大小是否和给定的子串大小相同
                if (len == s.size()) return true;
            }
        }
        return false;
    }
};

int main021229()
{
    string s = "ab" ,t = "hfbaljklkjl";
    Solution Overstr1;
    cout << "最小覆盖子串为: " << Overstr1.checkInclusion(s, t) << endl;
    return 0;
}