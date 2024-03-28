#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    //暴力解法
    int maxVowels1(string s, int k) {
        int l = 0;
        int right = k - 1;
        int count = 0;
        for (; right < s.size(); right++)
        {
            int ans = 0;
            for (int i = l; i <= right; i++)
            {
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                {
                    ans++;
                }
            }
            l++;
            count = max(count, ans);
        }
        return count;

    }
    //滑动窗口版本
    int maxVowels(string s, int k) {
        int l = 0;
        int right = 0;
        int count = 0;
        int ans = 0;
        for (; right < s.size(); right++)
        {
            if (s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' || s[right] == 'u')
            {
                ans++;
            }
            if (right - l + 1 == k)
            {
                count = max(count, ans);
                if (s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u')
                {
                    ans--;
                }
                l++;
            }
        }
        return count;
    }
};

int main01229()
{
    string s = "legfsadfgahfdahnvzbgdjnagdhafhsetcode";
    Solution s1;
    int k = 3;
    cout << "包含的元音字母个数为:" << s1.maxVowels(s, k) << endl;
    return 0;
}