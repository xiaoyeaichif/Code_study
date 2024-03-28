#include<iostream>
using namespace std;

void get(int a)
{
	int b = 0;
	for (int  i = 31; i >= 0; i--)
	{
		 b = (a & (1 << i ))==0?0:1;
		 cout << b;
	}
	cout << endl;
	
	
}

int main01()
{
	int a = 10;
	get(5);
	get(-5);
	cout << (-5 >> 1) << endl;
	/*cout << sizeof(int) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(float) << endl;
	cout << sizeof(double) << endl;
	cout << sizeof(long long) << endl;
	cout << INT_MAX<<endl;
	cout << INT_MIN;*/
	
	return 0;
}