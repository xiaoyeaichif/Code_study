#include<iostream>
using namespace std;
int main01011()
{
	//x������ֻ������,�������޸�
	const int x = 10;
	//�����Ҫ��ָ��ȡ���ĵ�ַ,����ʹ�ó���ָ��
	const int* p = &x;
	//����ת��,��constȥ��
	int *y = const_cast<int*>(p);
	cout << p << endl;
	cout << y << endl;
	cout << *y << endl;
	return 0;

}