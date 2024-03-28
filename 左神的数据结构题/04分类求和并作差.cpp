#include<iostream>
using namespace std;
class Solution {
public:
    int differenceOfSums(int n, int m)
    {
        int nums1 = 0;
        int nums2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i % m == 0 && i / m >= 1)
            {
                nums2 += i;
            }
            else {
                nums1 += i;
            }
        }
        return nums1 - nums2;
    }
};

int main010805()
{
    Solution s1;
    int n = 5, m = 1;
    int ans = s1.differenceOfSums(n, m);
    cout << ans;
    return 0;
}