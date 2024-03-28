#include<iostream>
#include<vector>
using namespace std;

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
{
    //特殊边界判断
    //数组为空,肯定找不到答案
    if (matrix.size() == 0 || matrix[0].size() == 0)
    {
        return false;
    }
    //获取数组的行数
    int m = matrix.size();
    //获取数组的列数
    int n = matrix[0].size();
    int i = 0;
    int j = n - 1;
    while (i < m && j >= 0)
    {
        if (matrix[i][j] == target)
        {
            return true;
        }
        else if (matrix[i][j] > target)
        {
            j--;
        }
        else {
            i++;
        }
    }
    return false;
}

//主函数
int main021603()
{
    vector<vector<int>>nums = {{2,3,6,8},{4,5,8,9},{5,9,10,12} };
    int target = 9;
    bool flag = findNumberIn2DArray(nums, target);
    cout << flag << endl;
    //加上boolalpha就可以直接输出true
    cout << boolalpha<<flag << endl;
    return 0;
}