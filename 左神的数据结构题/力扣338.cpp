#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for (int i = 0; i <= n; i++)
        {
            //ans.push_back(Getcount(i));
            ans[i] = Getcount(i);
        }
        return ans;
    }
    //获取数字当中1的个数
    int Getcount(int n)
    {
        int count = 0;
        while (n)
        {
            n = n & (n - 1);
            count += 1;
        }
        return count;
    }
};

int mainLC338()
{
    int n = 2;
    Solution s1;
    cout << s1.Getcount(n) << endl;
    vector<int>res = s1.countBits(n);
    for (int a : res)
    {
        cout << a << " " ;
    }
    cout << endl;
    return 0;
}