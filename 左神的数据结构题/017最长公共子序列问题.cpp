#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int process(string s1, string s2, int i, int j);
int Getlong(string s1,string s2)
{
	return process(s1, s2, s1.size() - 1, s2.size() - 1);
}

//ʵ�ַ���1
//��������������еĳ���
 //���ǵ����±���������Ӧģ��
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



//����2

//��������������еĳ���
//m,n�������ǰm(n)��Ԫ��
int LL(string s1, string s2, int m, int n) {
    // ��������������һ���ַ���Ϊ�գ�������Ӵ��ĳ���Ϊ0
    if (m == 0 || n == 0) {
        return 0;
    }

    // �����ǰ�ַ���ͬ���ݹ����
    //ǰ׺����Ϊm,�±������ķ�ΧΪ0--m-1������m-1-0+1 = m
    if (s1[m - 1] == s2[n - 1]) {
        return LL(s1, s2, m - 1, n - 1)+1;
    }

    // ����ÿ���ַ����ֱ�Ƚ�s1[i-1]��s2[j]�Լ�s1[i]��s2[j-1]�����
    //һ����������Ӧ��ֵ���ȣ����ȹ�Ϊ0�����¼���
    int length1 = LL(s1, s2, m - 1, n);
    int length2 = LL(s1, s2, m, n - 1);

    return max(length1, length2);
}


int GetLongestSubstringLength1(string s1, string s2) {
	int m = s1.length();
	int n = s2.length();
	//�����m��n������������±�
	return process(s1, s2, m-1, n-1);
}

int GetLongestSubstringLength2(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    //�����m��n�������ǰ׺����
    //���統m = 0ʱ����ǰ0�����ȣ�Ҳ�����ַ���Ϊ���ַ�
    return LL(s1, s2, m, n);
}

int main017() {
    string s1 = "1k2330HFHG210";
    string s2 = "32100kj00047";
	cout << "����������г���Ϊ��" << GetLongestSubstringLength1(s1, s2)<<endl;
    cout << "����������г���Ϊ��" << GetLongestSubstringLength2(s1, s2)<<endl;
    return 0;
}