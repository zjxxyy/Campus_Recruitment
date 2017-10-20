#include<iostream>
using namespace std;
class Parent{
public:
	Parent() :pdog(0), pcat(1), page(2), pwage(3)
	{
	}
	virtual  void say()
	{
		cout << "i am papa" << endl;
	}
	int pdog;
protected:
	int pcat;

private:
	int page;
	int pwage;
};
class Child :public Parent//去掉public  应该是私有继承 就是默认的继承方式
{
public:
	Child() :Parent(){}
	int getdog()
	{
		return pdog;
	}
	/*int getage()
	{

		return page;
	}*/
	int getpcat()
	{
		return pcat;
	}
	void say()
	{
		cout << "i am a child!" << endl;
	}
};
int main()
{
	Child a;
	Parent *p = &a;
	p->say();
  //如果前面基类没有虚函数，会输出i am a papa,有的话 会输出 i am a child!

	system("pause");
	return 0;
}
