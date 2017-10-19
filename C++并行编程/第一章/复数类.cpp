#include<iostream>
using namespace std;
class Ccomplex
{
public:
	Ccomplex()
	{
		dReal = 0;
		dImg = 0;
	}
	Ccomplex(double Real, double Img)
	{
		this->dReal = Real;
		this->dImg = Img;
	}
	Ccomplex(const Ccomplex &a)
	{
		this->dReal = a.dReal;
		this->dImg = a.dImg;
	}
	friend Ccomplex operator+(const Ccomplex  &a, const Ccomplex  &b);
	friend ostream&  operator<<(ostream &os, const Ccomplex &c);
	//Ccomplex operator=(const Ccomplex &a);
private:
	double dReal;
	double dImg;
};
Ccomplex operator+(const Ccomplex  &a, const Ccomplex  &b)
{
	Ccomplex c;
	c.dReal = a.dReal + b.dReal;
	c.dImg = a.dImg + b.dImg;
	return c;
}
ostream&  operator<<(ostream & os, const Ccomplex &c)
{
	return os << c.dReal << "+" << c.dImg << "i";
}
//Ccomplex Ccomplex::operator=(const Ccomplex &a)
//{
//	this->dReal = a.dReal;
//	this->dImg = a.dImg;
//	return *this;
//}
int main()
{
	Ccomplex a(3, 5);
	Ccomplex b(2, 3);
	Ccomplex c;
	c = a + b;
	cout << c << endl;
	system("pause");
	return 0;
}
