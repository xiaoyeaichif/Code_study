#include<iostream>
#include<string>
using namespace std;


string capitalizeTitle(string &title) {
    //ʹ��˫ָ��
    int left = 0;
    int right = 0;
    int size = title.size();
    while (right < size)
    {
        while (right < size && title[right] != ' ')
        {
            right += 1;
        }
        //�ж�l��r֮��ľ����Ƿ����2
        //����2,����ĸҪ��д,������ĸСд
        if (right - left > 2)
        {
            title[left] = toupper(title[left]);
            left += 1;
        }
        //������ĸҪСд
        while (left < right)
        {
            title[left] = tolower(title[left]);
            left += 1;
        }
        //�ƶ���ָ�뵽��ָ�����һ��Ԫ��
        left = right + 1;
        right += 1;
    }
    return title;
}
//
int main02129()
{
    string str = "capiTalIze tHe titLe";
    string res = capitalizeTitle(str);
    for (char c : res)
    {
        cout << c << ' ';
    }
    return 0;
}