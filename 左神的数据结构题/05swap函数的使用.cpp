#include<iostream>
#include<vector>
using namespace std;

void PRint(vector<int>& nums);
int main010703()
{
    vector<int>ans(10,0);
    for (int i = 0; i < 10; i++)
    {
        ans[i] = i;
    }
    PRint(ans);
    vector<int>res(3, 0),v;
    //��������������,ans���������ݸ���res,res���������ݸ���ans
    //���������ڽ�ʡ�ռ�
    ans.swap(res);
    PRint(res);
    PRint(ans);

    return 0;
}
void PRint(vector<int>& nums)
{
    /*for (vector<int>::iterator i = nums.begin(); i !=nums.end(); i++)
    {
        cout << *i << ' ';
    }*/
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}