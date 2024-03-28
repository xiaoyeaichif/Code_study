#include<iostream>
#include<vector>
using namespace std;

//��ȡ�����������ظ���Ԫ��
//�����е�Ԫ�ط�ΧΪ1-n
vector<int> findDuplicates(vector<int>& nums)
{
    int size = nums.size();
    if (size < 2) return {};
    vector<int>ans;
    for (int i = 0; i < size; i++)
    {
        if (nums[i] < 1 || nums[i] > size)
        {
            return {};
        }
    }
    for (int num : nums)
    {
        //-1����Ϊ��ֹ����Խ��
        // ֮ǰ�Ѿ��Ѷ�Ӧ������Ԫ�ر�ɸ����ˣ�
        // ��˵�� num �ظ�����������
        if (nums[abs(num) - 1] < 0)
        {
            ans.push_back(abs(num));
        }
        //�������е�ԭʼ������-1
        else {
            nums[abs(num) - 1] *= -1;
        }
    }
    return ans;
}

//������
int main0222004()
{
    vector<int> nums = { 2,3,1,2,1,3,5,6,7,8 };
    vector<int> ans = findDuplicates(nums);
    for (int num : ans)
    {
        cout << num << ' ';
    }
    return 0;
}