#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class rabbit{
public:

	rabbit()
	{
		age = 1;
		alive = true;
	}
	rabbit(int a, bool b)
	{
		age = a;
		alive = b;

	}
	rabbit & judge(int year, int limitage)
	{
		age++;
		if (age >= limitage)
			alive = false;
		if ((age ==3))
		{
			rabbit a;
			return a;
		}
		else if ((age > 3)&&(this->alive==true))
		{
			rabbit a;
			return a;
		}
		else
		{
			rabbit b(0,false);
			return b;
		}

	}
	void setalive(bool b)
	{
		alive = b;
	}
	int  getage()
	{
		return age;
	}
	bool getalive()
	{

		return alive;
	}
private:
	int age;
	bool alive;
};
bool compareage(rabbit a, rabbit b)
{
	if (a.getage() > b.getage())
		return true;
	else
		return false;

}
int main()
{
	int x, y;
	cin >> x >> y;
	rabbit mather, father;
	vector<rabbit> tuzi;
	tuzi.push_back(mather);
	tuzi.push_back(father);
	for (int i = 1; i < y; i++)
	{
		int n= tuzi.size();

		for (int j = 0; j < n; j++)
		{
			rabbit temp=tuzi[j].judge(i, x);
			if (temp.getalive())
				tuzi.push_back(temp);
		}
		if (i>10)
		{
			sort(tuzi.begin(), tuzi.end(), compareage);
			int jilu = 0;
			for (vector<rabbit>::iterator it = tuzi.begin(); it != tuzi.end(); it++)
			{
				if (jilu < 2)
				{
					if (it->getalive())
						it->setalive(false);
					jilu++;
				}
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < tuzi.size(); i++)
	{
		if (tuzi[i].getalive())
			sum += tuzi[i].getage();
	}
	cout << sum;
	//system("pause");
	return 0;
}
