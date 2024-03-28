#include<iostream>
#include<vector>
using namespace std;


//�˷��Ƚ�ʡ�ڴ�
class Solution {
public:
    //����һЩȫ�ֱ���ʹ��
    const int static MAX = 100001;
    int deque[MAX] = { 0 };
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        // const int MAX = 100001;
        // vector<int>deque(MAX);
        //start�����ʼλ�ã�
        //end���������Ԫ�صĸ���,���еĶ���Ԫ��ָ��Ϊend-1
        int start = 0, end = 0;
        int N = nums.size();
        //�Ƚ�ǰk-1��Ԫ�ص��±������Ž�������
        for (int i = 0; i < k - 1; i++)
        {
            while (start < end && nums[deque[end - 1]] <= nums[i])
            {
                end--;
            }
            deque[end] = i;
            end++;
        }
        //�����������
        int  m = N - k + 1;
        vector<int>ans(m);
        //���Ԫ�ؽ�����
        for (int l = 0, r = k - 1; l < m; l++, r++)
        {
            while (start < end && nums[deque[end - 1]] <= nums[r])
            {
                end--;
            }
            deque[end] = r;
            end++;
            //���ֵ��deque�Ķ�ͷλ��
            ans[l] = nums[deque[start]];
            //��ֹһЩԪ���Ѿ�������
            if (deque[start] == l)
            {
                start++;
            }
        }
        return ans;
    }
};

int main25()
{
    Solution s1;
    int k = 3;
    vector<int>ans;
    vector<int>res = { 1,3,-1,-3,5,6,1,25,45,6,7 };
    ans = s1.maxSlidingWindow(res,k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout <<ans[i] << " ";
    }
    return 0;
}