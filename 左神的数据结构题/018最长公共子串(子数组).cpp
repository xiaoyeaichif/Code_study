#include<iostream>
#include<string>
using namespace std;


//返回最长公共子串或者数组的长度
int findLongestSubstring(string s1, string s2, int m, int n, int length) {
    // 基本情况：如果有一个字符串为空，最长公共子串的长度为0
    if (m == 0 || n == 0) {
        return length;
    }

    // 如果当前字符相同，递归调用
    //前缀长度为m,下标索引的范围为0--m-1，由于m-1-0+1 = m
    if (s1[m - 1] == s2[n - 1]) {
        length = findLongestSubstring(s1, s2, m - 1, n - 1, length + 1);
    }

    // 对于每个字符，分别比较s1[i-1]和s2[j]以及s1[i]和s2[j-1]的情况
    //一旦索引所对应的值不等，长度归为0，重新计算
    int length1 = findLongestSubstring(s1, s2, m - 1, n, 0);
    int length2 = findLongestSubstring(s1, s2, m, n - 1, 0);

    return max(length, max(length1, length2));
}

int GetLongestSubstringLength(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    //传入的m和n代表的是前缀长度
    //比如当m = 0时代表，前0个长度，也就是字符串为空字符
    return findLongestSubstring(s1, s2, m, n, 0);
}

int main018() {
    string s1 = "1233021";
    string s2 = "32147";
    cout << "最长公共子串长度为：" << GetLongestSubstringLength(s1, s2);
    return 0;
}
