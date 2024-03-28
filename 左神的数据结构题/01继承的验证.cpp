#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	void speak()
	{
		cout << "������˵��" << endl;
	}
};
class Cat :public Person {
public:
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};

class Dog :public Person {
public:
	void speak()
	{
		cout << "С����˵��" << endl;
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