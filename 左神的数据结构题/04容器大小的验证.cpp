#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<deque>
#include<set>
#include<map>
using namespace std;

void printOut(vector<int>&nums)
{
	for (size_t i = 0; i < nums.size(); i++)
	{
		cout << nums[i] <<' ';
	}
	cout << endl;
	
}

int mainstl04()
{
	vector<int>ans = {1,21,3,5,5};
	cout << ans.size() << endl;
	cout << ans.capacity() << endl;
	ans.push_back(6);
	//扩容之后
	cout << ans.size() << endl;
	cout << ans.capacity() << endl;
	cout << sizeof(ans) << endl;
	//使用区间插入元素
	vector<int>res = { 1,2,3 };
	//在开头两个指针,插入整个res
	ans.insert(ans.begin()+ 2, res.begin(), res.end());
	printOut(ans);
	cout << ans.size() << endl;
	cout << ans.capacity() << endl;
	//区间删除
	ans.erase(ans.begin(), ans.begin() + 5);
	printOut(ans);
	return 0;
}