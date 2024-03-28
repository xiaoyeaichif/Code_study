#include<iostream>
#include<string>
using namespace std;


//����������Ӵ���������ĳ���
int findLongestSubstring(string s1, string s2, int m, int n, int length) {
    // ��������������һ���ַ���Ϊ�գ�������Ӵ��ĳ���Ϊ0
    if (m == 0 || n == 0) {
        return length;
    }

    // �����ǰ�ַ���ͬ���ݹ����
    //ǰ׺����Ϊm,�±������ķ�ΧΪ0--m-1������m-1-0+1 = m
    if (s1[m - 1] == s2[n - 1]) {
        length = findLongestSubstring(s1, s2, m - 1, n - 1, length + 1);
    }

    // ����ÿ���ַ����ֱ�Ƚ�s1[i-1]��s2[j]�Լ�s1[i]��s2[j-1]�����
    //һ����������Ӧ��ֵ���ȣ����ȹ�Ϊ0�����¼���
    int length1 = findLongestSubstring(s1, s2, m - 1, n, 0);
    int length2 = findLongestSubstring(s1, s2, m, n - 1, 0);

    return max(length, max(length1, length2));
}

int GetLongestSubstringLength(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    //�����m��n�������ǰ׺����
    //���統m = 0ʱ����ǰ0�����ȣ�Ҳ�����ַ���Ϊ���ַ�
    return findLongestSubstring(s1, s2, m, n, 0);
}

int main018() {
    string s1 = "1233021";
    string s2 = "32147";
    cout << "������Ӵ�����Ϊ��" << GetLongestSubstringLength(s1, s2);
    return 0;
}
