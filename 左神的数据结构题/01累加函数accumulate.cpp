#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Myclass {
public:
	int operator()(int x, int y)
	{
		return x + 3 * y;
	}
};


int mainAccum()
{
	int init = 100;
	vector<int>nums = { 10,20,30 };
	//accumulate�������汾
	//һ���汾��Ҫ����������һ���汾��Ҫ�ĸ�����
	int res = accumulate(nums.begin(),nums.end(),init);
	cout << "�ۼӺ�Ϊ:" << res<<endl;
	//�ĸ������汾,���ĸ�����Ϊ��������
	int res1 = accumulate(nums.begin(), nums.end(),init, Myclass());
	cout << "�ۼӺ�Ϊ:" << res1 << endl;
	return 0;
}