#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	class mycircle{
	public:
		mycircle() :x(0), y(0)
		{
		}
		void changenumbers(char ch)
		{
			switch (ch){
			case 'U': y++; break;
			case 'D': y--; break;
			case 'R': x++; break;
			case 'L': x--; break;
			default: break;
			}
		}
		bool is_acircle()
		{
			if (x == 0 && y == 0)
				return true;
			else
				return false;
		}
	private:
		int x;
		int y;
	};
	bool judgeCircle(string moves) {
		mycircle a;
		for (int i = 0; i < moves.size(); i++)
			a.changenumbers(moves[i]);
		if (a.is_acircle())
			return true;
		else
			return false;
	}
};
int main()
{
	Solution s;
	string c;
	cin >> c;
	cout <<boolalpha <<s.judgeCircle(c);
	system("pause");
	return 0;
}
