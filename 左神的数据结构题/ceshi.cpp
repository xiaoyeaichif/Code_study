#include<iostream>
using namespace std;
int main21()
{
	int i = 10;
	int j = 11;
	//����ָ��
	const int* p = &i;
	//ָ�볣��
	int* const p1 = &i;
	p = &j;
	*p1 = j;
	cout << &i << endl;
	cout << *p << endl;
	cout << p1 << endl;
	cout << *p1 << endl;
	return 0;
}