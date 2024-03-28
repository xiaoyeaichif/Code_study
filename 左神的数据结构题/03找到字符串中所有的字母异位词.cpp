#include<iostream>
#include<string>
#include<vector>
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
        int left = 0;
        int debt = p.size();
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
                if (right - left + 1 == p.size())
                {
                    ans.push_back(left);
                }
            }
        }
        return ans;
    }
};

int main031229()
{
    string s = "abab", t = "ab";
    Solution Overstr2;
    vector<int>ans = Overstr2.findAnagrams(s, t);
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}