#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int countKeyChanges(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if ('A' <= s[i] <= 'Z')
            {
                s[i] = s[i] + 32;
            }
        }
        int ans = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != s[i - 1])
            {
                ans += 1;
            }
        }
        return ans;
    }
};
int main0216()
{
	string str = "anbcABC";
	for (int i = 0; i < str.size(); i++)
	{
		if ('A' <= str[i] && str[i] <= 'Z')
		{
			str[i] += 32;
		}
	}
	for (char c : str)
	{
		cout << c ;
	}
	cout << endl;
	return 0;
}