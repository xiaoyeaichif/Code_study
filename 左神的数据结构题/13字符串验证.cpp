#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int dayOfYear(string date) {
        //stoi�����Ὣ�ַ���"01"ת��Ϊ1,�����Զ�����ǰ���0
        //�����Ҫǰ���0����������������setw()����
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        cout << year << " " << month << " " << day << endl;

        int amount[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            ++amount[1];
        }

        int ans = 0;
        for (int i = 0; i < month - 1; ++i) {
            ans += amount[i];
        }
        return ans + day;
    }
};

int mainMonth()
{
    string str = "2019-11-02";
    Solution Y;
    cout << Y.dayOfYear(str) << endl;
    return 0;
}