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
    //经过这样操作后,ans的所有数据给了res,res的所有数据给了ans
    //这样有助于节省空间
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