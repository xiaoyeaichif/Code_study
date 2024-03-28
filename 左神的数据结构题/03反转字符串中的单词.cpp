#include<iostream>
#include<string>
using namespace std;

string Remove_KG(string s)
{
	int N = s.size();
	string str = "";
	for (int i = 0; i < N; i++)
	{
		if (i == 0 && s[0] == ' ' || i == N-1 && s[N - 1] == ' ')
		{
			continue;
		}
		if (s[i] != ' ')
		{
			str += s[i];
		}
		else if (s[i] == ' ')
		{
			if (s[i - 1] != ' ')
			{
				str += s[i];
			}
		}
	}
	if (str.back() == ' ')
	{
		str.pop_back();
	}
	return str;
}
//反转字符串逻辑
string transStr(string s)
{
	int l = 0;
	int r = s.size() - 1;
	while (l < r)
	{
		swap(s[l], s[r]);
		l++;
		r--;
	}
	return s;
}

int main010802()
{
	string s = "the sky is blue";
	cout << Remove_KG(s).size() << "==" << Remove_KG(s) << endl;
	string str = Remove_KG(s);
	string s1 = "";
	int j = str.size() - 1;
	while (j >= 0)
	{
		s1 += str[j];
		j--;
	}
	cout << "字符串s1:" << s1 << endl;
	s1.push_back(' ');
	string s2 = "";
	int left = 0;
	for (int right = 0; right < s1.size(); right++)
	{
		if (s1[right] == ' ')
		{
			string s3 = s1.substr(left, right - left);
			s2 += transStr(s3);
			s2 += ' ';
			left = right + 1;
		}
	}
	//把最后一个字符去掉
	s2.pop_back();
	cout << s2 << endl;
	return 0;
}