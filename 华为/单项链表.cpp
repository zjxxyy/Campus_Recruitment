#include<iostream>
#include<vector>
using namespace std;


struct ListNode {
	int m_nKey;
	ListNode* m_pNext;
	ListNode(){}
	ListNode(int a) {
		m_nKey = a;
		m_pNext = NULL;
	}
};
class Solution{
public:

	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k, int nums)
	{

		ListNode* p = pListHead;
		for (int i = 0; i <= nums - k; ++i)
			p = p->m_pNext;
		return p;

	}



};

int main()
{
	int n;

	while (cin >> n)
	{




		ListNode *pHead = new ListNode(-1);
		ListNode *p = pHead;
		for (int i = 0; i < n; ++i){
			int data;
			cin >> data;
			ListNode *q = new ListNode(data);
			p->m_pNext = q;
			p = p->m_pNext;
		}

		int k;
		cin >> k;
		p = pHead;
		if (k == 0)  // 边界测试
			cout << "0" << endl;
		else
		{


			/*if (n - k>= 0){
				for (int i = 0; i <= n- k; ++i)
					p = p->m_pNext;
				cout << p->m_nKey << endl;
			}
			else
		 cout << "NULL" << endl;*/
			Solution s;
			if (n - k >= 0)
			{
				ListNode* q = s.FindKthToTail(pHead, k, n);
				if (q != NULL)
					cout << q->m_nKey<<endl;//这一道题目就是没有加换行符 最后居然错了。。。。
			}

			else
				cout << "NULL";
		}



	}

	system("pause");
	return 0;
}
