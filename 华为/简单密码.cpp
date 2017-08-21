#include<iostream>
#include<string>
using namespace std;
char jiamichar(char ch);
string jiami(string a)
{
	string b = "";
	for (int i = 0; i < a.size(); i++)
		b += jiamichar(a[i]);
	return b;

}
char jiamichar(char ch)
{

	switch (ch){
	case '1':return '1';
	case 'a':
	case 'b':
	case 'c': return '2';
	case 'e':
	case 'd':
	case 'f': return '3';
	case 'g':
	case 'h':
	case 'i': return '4';
	case 'j':
	case 'k':
	case 'l': return '5';
	case 'm':
	case 'n':
	case 'o': return '6';
	case 'p':
	case 'q':
	case 'r':
	case 's': 	return '7';
	case 't':
	case 'u':
	case 'v': 	return '8';
	case 'w':
	case 'x':
	case 'y':
	case 'z': 	return '9';
	case '0': return '0';
	case 'Z':return 'a';
	case '2': return '2';
	case '3': return '3';
	case '4': return '4';
	case '5': return '5';
	case '6': return '6';
	case '7': return '7';
	case '8': return '8';
	case '9': return '9';
	default: return  'a' - 'A' + ch + 1;
	}

}
int main()
{
	string a;
	cin >> a;
	cout << jiami(a) << endl;

	system("pause");
	return 0;
}
