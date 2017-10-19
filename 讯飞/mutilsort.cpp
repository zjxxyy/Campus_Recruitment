#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class team
{
public:
	string name;
	int score;
	int jingshengqiu;
	int jingqiushu;
	team()
	{
		score = 0;
		jingshengqiu = 0;
		jingqiushu = 0;
	}
	team(const team &a)
	{
		this->name = a.name;
		this->jingqiushu = a.jingqiushu;
		this->score = a.score;
		this->jingshengqiu = a.jingshengqiu;
	}
	team & operator=(const team &a)
	{
		this->name = a.name;
		this->jingqiushu = a.jingqiushu;
		this->score = a.score;
		this->jingshengqiu = a.jingshengqiu;
		return *this;
	}
	friend void judge(team &a, team &b, int ascore, int bscore);
	~team()
	{
		score = 0;
		jingshengqiu = 0;
		jingqiushu = 0;
	}

};
void judge(team &a, team &b, int ascore, int bscore)
{
	if (ascore > bscore)
	{
		a.score += 3;
		a.jingshengqiu = ascore - bscore;
		a.jingqiushu += ascore;
		b.jingqiushu += bscore;
	}
	else if (ascore == bscore)
	{
		a.score +=1;
		b.score += 1;
		a.jingqiushu += ascore;
		b.jingqiushu += bscore;
	}
	else
	{
		b.score += 3;
		b.jingshengqiu = bscore - ascore;
		a.jingqiushu += ascore;
		b.jingqiushu += bscore;
	}
	cout << a.name << " " << a.score << " " << a.jingshengqiu << " " << a.jingqiushu << endl;
	cout << b.name << " " << b.score << " " << b.jingshengqiu << " " << b.jingqiushu << endl;

}
//自定义比较函数要想成功，必须要有自己的拷贝构造函数和=运算符的重载函数。
bool mycompare(const team &a, const team &b)
{
	if (a.score > b.score)
		return true;
	else if (a.score == b.score)
	{
		if (a.jingshengqiu > b.jingshengqiu)
			return true;
		else if (a.jingshengqiu == b.jingshengqiu)
		{
			if (a.jingqiushu > b.jingqiushu)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;

}
string chuli1(string a)
{
	int index1 = a.find("-",0);
	string b="";
	for (int i = 0; i < index1; i++)
		b += a[i];
	return b;
}
string chuli2(string a)
{
	int index1 = a.find("-", 0);
	int index2 = a.find(" ",0);
	string b = "";
	for (int i = index1+1; i < index2;i++)
		b += a[i];
	return b;

}
int  chuli3(string a)
{
	int index2 = a.find(" ", 0);
	int index3 = a.find(":", 0);
	int sum = 0;
	for (int i = index2 + 1; i < index3; i++)
		sum += a[i] - '0';
	return sum;
}
int chuli4(string a)
{
	int index3 = a.find(":", 0);
	int sum = 0;
	for (int i = index3 + 1; i < a.size();i++)
		sum += a[i] - '0';
	return sum;
}
int main()
{
	int n;
	while (cin >> n)
	{
		cin.clear();
		cin.sync();
		vector<team> p(n);
		for (int i = 0; i < n; i++)
			getline(cin,p[i].name);
		for (int i = 0; i < n; i++)
			cout << p[i].name << endl;
		cout << p.size() << endl;


		map<string, int> mymap;
		for (int i = 0; i < n; i++)
			mymap[p[i].name] = i;


		string a, b;
		int ascore, bscore;
		for (int j = 0; j < n*(n - 1) / 2; j++)
		{
			string d;
			getline(cin, d);
			a = chuli1(d);
		//	cout << a << endl;

			b = chuli2(d);
			//cout << b << endl;
			ascore = chuli3(d);
			//cout << ascore << endl;

			bscore = chuli4(d);
			//cout << bscore << endl;

			judge(p[mymap[a]], p[mymap[b]], ascore, bscore);
		}
		for (int i = 0; i < p.size(); i++)
			cout << p[i].name << " " << p[i].score << " " << p[i].jingshengqiu << " " << p[i].jingqiushu << endl;

		sort(p.begin(),p.end(),mycompare);
		for (int i = 0; i < p.size(); i++)
			cout << p[i].name << " " << p[i].score << " " << p[i].jingshengqiu << " " << p[i].jingqiushu << endl;
		for (int i = 0; i < n / 2; i++)
			cout << p[i].name << endl;

	}


}
