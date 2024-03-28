#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        //生成一个存放起始索引的数组
        vector<int>ans;
        //生成一个数组，存放已经存在的字母
        int res[26] = { 0 };
        for (char c : p)
        {
            res[c - 'a']--;
        }
        int left = 0, start = 0;
        int debt = p.size();
        int len = INT_MAX;
        for (int right = 0; right < s.size(); right++)
        {
            char cur = s[right];
            res[cur - 'a']++;
            if (res[cur - 'a'] <= 0)
            {
                debt--;
            }
            if (debt == 0)
            {
                while (res[s[left] - 'a'] > 0)
                {
                    res[s[left] - 'a']--;
                    left++;
                }
                if (right - left + 1 <= len)
                {
                    len = right - left + 1;
                    start = left;
                }
                if (len == p.size() && right - left + 1 == p.size())
                {
                    ans.push_back(start);
                }

            }
        }
        return ans;
    }
};

int main()
{
    Solution s1;
    string s = "cbaebabacd";
    string t = "abc";
    s1.findAnagrams(s,t);
    return 0;
}