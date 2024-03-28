#include<iostream>
using namespace std;
int main01011()
{
	//x现在是只读变量,不可以修改
	const int x = 10;
	//如果想要用指针取它的地址,必须使用常量指针
	const int* p = &x;
	//类型转换,把const去除
	int *y = const_cast<int*>(p);
	cout << p << endl;
	cout << y << endl;
	cout << *y << endl;
	return 0;

}