#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution{
public:
	int fama(int n, vector<int> weight, vector<int> nums)
	{
		vector<int> store_kinds;

		store_kinds.push_back(0);//初始化weigths数组
		for (int i = 1; i <= nums[0]; i++)
		{
			store_kinds.push_back(i*weight[0]);//将第一个砝码能称出的所有质量入队。
		}
		for (int i = 1; i < n; i++)
		{

			int len = store_kinds.size();

			for (int k = 1; k <= nums[i]; k++)
			{

				for (int z = 0; z < len; z++)
				{
					int wei = store_kinds[z] + k*weight[i];//将该质量的砝码数依次与前面所有的砝码数相加
					if (find(store_kinds.begin(), store_kinds.end(), wei) == store_kinds.end())//如果之前没有这个质量的砝码就将其入队
						store_kinds.push_back(wei);
				}

			}


		}
		return store_kinds.size();
	}
  //下面是我写的一个二分查找法。
	bool numinvector(int num,vector<int> a)
	{
		int flag = 0;
		int head = 0;
		int tail = a.size()-1;
		int middle = 0;
		while (head < tail)
		{
			middle = (head + tail) / 2;
			if (a[middle] < num)
				head = middle + 1;
			if (a[middle]>num)
				tail = middle - 1;
			if (a[middle] == num)
			{
				flag = 1;
				break;
			}
		}
		if (tail <= a.size() - 1)
		{
			if (a[tail] == num)
				flag = 1;
		}

		if (flag == 1)
			return true;
		else
			return false;
	}
};
int main()
{
	int n;
  //vector<int> weight;
  //vector<int> nums; 开始我在这里定义容器，后来发现错了，因为容器会在输入后会一直改变，如果这里定义，会出错，。
	Solution s;
	//cin >> n;
	/*for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		weight.push_back(temp);
	}
	int t;
	cin >> t;
	cout << s.numinvector(t, weight);*/
	while (cin >> n)
	{
		vector<int> weight;
		vector<int> nums;
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			weight.push_back(temp);
		}
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			nums.push_back(temp);
		}
		/*int t;
		cin >> t;
		cout << s.numinvector(t, nums);*/
		cout << s.fama(n, weight, nums)<<endl;
	}

	system("pause");
	return 0;
}
