#include<iostream>
#include<string>
using namespace std;


string capitalizeTitle(string &title) {
    //使用双指针
    int left = 0;
    int right = 0;
    int size = title.size();
    while (right < size)
    {
        while (right < size && title[right] != ' ')
        {
            right += 1;
        }
        //判断l和r之间的距离是否大于2
        //大于2,首字母要大写,其他字母小写
        if (right - left > 2)
        {
            title[left] = toupper(title[left]);
            left += 1;
        }
        //其余字母要小写
        while (left < right)
        {
            title[left] = tolower(title[left]);
            left += 1;
        }
        //移动左指针到右指针的下一个元素
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