#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//    int minimumPushes(string word)
//    {
//        vector<int>res1(26, 0);
//        int N = word.size();
//        for (int i = 0; i < N; i++)
//        {
//            res1[word[i] - 'a'] += 1;
//        }
//        sort(res1.begin(), res1.end(),greater<int>());
//        int ans = 0;
//        for (int i = 0; i < 26; i++)
//        {
//            if (i <= 7)
//            {
//                ans += res1[i];
//            }
//            else if (i <= 15)
//            {
//                ans += res1[i] * 2;
//            }
//            else if (i <= 23)
//            {
//                ans += res1[i] * 3;
//            }
//            else {
//                ans += res1[i] * 4;
//            }
//        }
//        return ans;
//
//    }
//};
int main0121()
{
    string str = "iudgsde";
    //Solution s1;
    //cout << s1.minimumPushes(str) << endl;
    return 0;
}