#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	void speak()
	{
		cout << "动物在说话" << endl;
	}
};
class Cat :public Person {
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};

class Dog :public Person {
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};

void DoSpeak(Person& animal)
{
	animal.speak();
}
void test01()
{
	Cat cat;
	DoSpeak(cat);
}
void DoSpeak(Cat& animal)
{
	animal.speak();
}
void test02()
{
	Cat cat;
	DoSpeak(cat);
}



int main1029()
{
	test01();
	test02();
	return 0;
}