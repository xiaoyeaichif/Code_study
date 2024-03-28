#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions)
    {
        int S = 0;
        int ans = 0;
        for (vector<int>&arr : dimensions)
        {
            if ((arr[0] * arr[0] + arr[1] * arr[1]) >= ans)
                // ans = max(arr[0]^2+arr[1]*2,ans);
            {
                ans = (arr[0] * arr[0] + arr[1] * arr[1]);
                S = arr[0] * arr[1];
            }
        }
        return S;
    }
};

int main010701()
{
    vector<vector<int>> dimensions = { {9,3},{8,6},{20,1},{8,8} };
    Solution s1;
    cout << s1.areaOfMaxDiagonal(dimensions) << endl;
    return 0;
}