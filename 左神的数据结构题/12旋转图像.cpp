#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        //先转置,后交换
        int M = matrix.size();
        int N = matrix[0].size();
        for (int i = 0; i < M; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //交换每一行的元素
        for (vector<int> & nums : matrix)
        {
            int i = 0;
            int j = nums.size() - 1;
            while (i < j)
            {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
    }
};
int main010601()
{
    vector<vector<int>>nums = { {1,2,3},{4,5,6},{7,8,9} };
    Solution s1;
    s1.rotate(nums);
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = 0; j < nums[0].size(); j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}