#include<iostream>
#include<string>
using namespace std;

//����1
//�������ʹ���˶���Ŀռ�
string Swap_Kg(string s)
{
	string ans = "";
	for (char c : s)
	{
		if (c == ' ')
		{
			ans += "%20";
		}
		else {
			ans += c;
		}
		
	}
	return ans;
}

//����2
//�Ȱ��ַ����ĳ��������
string Get_str(string &str)
{
	string s = str;
	int count = 0;
	for (char c : s)
	{
		if (c == ' ')count += 1;
	}
	//�Ȱ�ԭ���ַ��������һ���±��¼����
	int p1 = s.size() - 1;
	for (int i = 0; i < 3 * count - 2; i++)
	{
		s += ' ';
	}
	//�仯����������һ���±�
	int p2 = s.size() - 1;
	while (p1 >= 0 && p1 < p2)
	{
		if (s[p1] == ' ')
		{
			s[p2--] = '0';
			s[p2--] = '2';
			s[p2--] = '%';
		}
		else {
			s[p2] = s[p1];
			p2--;
		}
		p1--;
	}
	/*for (char c : s)
	{
		cout << c << endl;
	}*/
	return s;

}

//��������ʵ��
int main022005()
{
	string s = "We are happy";
	cout << Swap_Kg(s) << ' ' << s.size() << endl;
	cout<<Get_str(s);
	return 0;
}