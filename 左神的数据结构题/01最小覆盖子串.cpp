#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        //�߽�����
        if (s.size() < t.size()) return "";
        vector<int>ans(128, 0);
        int debt = t.size();
        int N = s.size();
        int left = 0;
        //��ΪҪ����Сֵ,��INT_MAX��¼
        int len = INT_MAX;
        ///����left��λ��
        int start = 0;
        //��ʼ����Ҫ���ַ�
        for (char c : t)
        {
            ans[c]--;
        }
        for (int right = 0; right < N; right++)
        {
            ans[s[right]]++;
            //ֻ�г��ֹ���Ԫ��++���С�ڵ���0,֮ǰû���ֹ���++������0
            if (ans[s[right]] <= 0)
            {
                debt--;
            }
            //�����ʱ�Ĵ������Ѿ�����t������Ԫ��
            if (debt == 0)
            {
                while (ans[s[left]] > 0)
                {
                    //��Ԫ���³�����,leftָ������
                    ans[s[left]]--;
                    left++;
                }
                //��˭��С
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
    cout << "��С�����Ӵ�Ϊ: " << Overstr.minWindow(s, t) << endl;
    return 0;
}