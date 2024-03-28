#include<iostream>
using namespace std;
int main21()
{
	int i = 10;
	int j = 11;
	//常量指针
	const int* p = &i;
	//指针常量
	int* const p1 = &i;
	p = &j;
	*p1 = j;
	cout << &i << endl;
	cout << *p << endl;
	cout << p1 << endl;
	cout << *p1 << endl;
	return 0;
}