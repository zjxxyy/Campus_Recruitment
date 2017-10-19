#include<iostream>

using namespace std;
void quicksort(int left, int right, int a[])
{

	if (left >= right)
		return;
	int k = a[left];
	int right_t = right;
	while (left < right)
	{
		while (a[right]>k&&left<right)
			right--;
		a[left] = a[right];
		while (a[left] < k&&left<right)
			left++;
		a[right] = a[left];
		/*for (int i = 0; i < 5; i++)
			cout << a[i] << " ";
		cout << "left=" << left << "right=" << right;*/
		//cout << endl;

	}
	a[left] = k;//right==left
	//for (int i = 0; i < 5; i++)
	//	cout << a[i] << " ";

	quicksort(0, left - 1, a);
	quicksort(left + 1, right_t, a);
}
int main()
{
	int a[5];
	for (int i = 0; i < 5; i++)
		cin >> a[i];
	quicksort(0, 4, a);
	for (int i = 0; i < 5; i++)
		cout << a[i] << " ";
	cout << endl;
	system("pause");
	return 0;

}
