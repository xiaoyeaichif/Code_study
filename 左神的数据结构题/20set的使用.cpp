#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

int countWords(vector<string>& words1, vector<string>& words2)
{
    set<string>s1(words1.begin(), words1.end());
    set<string>s2(words2.begin(), words2.end());
    int ans = 0;
    for (auto& u : s1)
    {
        if (s2.count(u) == 1)
        {
            ans += 1;
        }
    }
    return ans;
}

int main0121020(){

    vector<string>words1 = { "leetcode", "is", "amazing", "as", "is" };
    vector<string>words2 = { "amazing", "leetcode", "is" };
    cout << countWords(words1, words2) << endl;
    return 0;
}