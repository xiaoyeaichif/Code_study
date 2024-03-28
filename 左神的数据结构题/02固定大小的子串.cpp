#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s, string t) {
        //�߽�����
        if (s.size() > t.size()) return false;
        vector<int>ans(128, 0);
        //�͵�һ��Ŀ��һ���ĵط�,���Ĵ��붼��һ����
        int debt = s.size();
        int N = t.size();
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
                //������С�ĸ����ִ���С�Ƿ�͸������Ӵ���С��ͬ
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
    cout << "��С�����Ӵ�Ϊ: " << Overstr1.checkInclusion(s, t) << endl;
    return 0;
}