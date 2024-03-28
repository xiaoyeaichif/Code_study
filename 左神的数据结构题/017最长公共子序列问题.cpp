#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int process(string s1, string s2, int i, int j);
int Getlong(string s1,string s2)
{
	return process(s1, s2, s1.size() - 1, s2.size() - 1);
}

//实现方法1
//返回最长公共子序列的长度
 //考虑的是下标索引做对应模型
int process(string s1, string s2, int i, int j)
{
	if (i == 0 && j == 0)
	{
		return s1[i] == s2[j] ? 1 : 0;
	}
	else if (i == 0)
	{
		if (s1[i] == s2[j])
		{
			return 1;
		}
		else {
			return process(s1, s2, i, j - 1);
		}
	}
	else if (j == 0)
	{
		if (s1[i] == s2[j])
		{
			return 1;
		}
		else {
			return process(s1, s2, i-1, j );
		}
	}
	else {
		int p1 = process(s1, s2, i, j - 1);
		int p2 = process(s1, s2, i - 1, j);
		int p3 = s1[i] == s2[j]? process(s1, s2, i - 1, j-1)+1:0;
		return max(p1, max(p2, p3));
	}
}



//方法2

//返回最长公共子序列的长度
//m,n代表的是前m(n)个元素
int LL(string s1, string s2, int m, int n) {
    // 基本情况：如果有一个字符串为空，最长公共子串的长度为0
    if (m == 0 || n == 0) {
        return 0;
    }

    // 如果当前字符相同，递归调用
    //前缀长度为m,下标索引的范围为0--m-1，由于m-1-0+1 = m
    if (s1[m - 1] == s2[n - 1]) {
        return LL(s1, s2, m - 1, n - 1)+1;
    }

    // 对于每个字符，分别比较s1[i-1]和s2[j]以及s1[i]和s2[j-1]的情况
    //一旦索引所对应的值不等，长度归为0，重新计算
    int length1 = LL(s1, s2, m - 1, n);
    int length2 = LL(s1, s2, m, n - 1);

    return max(length1, length2);
}


int GetLongestSubstringLength1(string s1, string s2) {
	int m = s1.length();
	int n = s2.length();
	//传入的m和n代表的是数组下标
	return process(s1, s2, m-1, n-1);
}

int GetLongestSubstringLength2(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    //传入的m和n代表的是前缀长度
    //比如当m = 0时代表，前0个长度，也就是字符串为空字符
    return LL(s1, s2, m, n);
}

int main017() {
    string s1 = "1k2330HFHG210";
    string s2 = "32100kj00047";
	cout << "最长公共子序列长度为：" << GetLongestSubstringLength1(s1, s2)<<endl;
    cout << "最长公共子序列长度为：" << GetLongestSubstringLength2(s1, s2)<<endl;
    return 0;
}