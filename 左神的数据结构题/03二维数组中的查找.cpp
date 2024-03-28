#include<iostream>
#include<vector>
using namespace std;

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
{
    //����߽��ж�
    //����Ϊ��,�϶��Ҳ�����
    if (matrix.size() == 0 || matrix[0].size() == 0)
    {
        return false;
    }
    //��ȡ���������
    int m = matrix.size();
    //��ȡ���������
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

//������
int main021603()
{
    vector<vector<int>>nums = {{2,3,6,8},{4,5,8,9},{5,9,10,12} };
    int target = 9;
    bool flag = findNumberIn2DArray(nums, target);
    cout << flag << endl;
    //����boolalpha�Ϳ���ֱ�����true
    cout << boolalpha<<flag << endl;
    return 0;
}