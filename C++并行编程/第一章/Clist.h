#ifndef _LIST_
#define _LIST_
#include<Windows.h>

template <class T>
class CNode{
public:
	CNode(T* tElement) :tElement(tElement), next(0){}
	T* Element() const{ return tElement; }
	CNode*& Next(){ return next; }
private:
	T* tElement;
	CNode* next;

};
template <class T>
class Clist{
public:
	Clist():dwCount(0),head(0){}

	Clist(T* tElement) :dwCount(1), head(new CNode<T>(tElement)){ }

	virtual ~Clist(){}
	void Append(CNode<T>*& node, T* tElement);
	void Insert(T* tElement);
	bool Remove(T* tElement);
	DWORD Count() const{ return dwCount; }
	CNode<T>* &Head(){ return head; }
	T* Getfirt(){ return head != NULL ? head->Element() : NULL; }
	T* Getlast();
	T* Getnext(T* tElement);
	T* Find(DWORD(*Function)(T* tParameter), DWORD dwValue);
protected:
	Clist(const Clist & list);
	Clist & operator=(const Clist & list);

private:
	CNode<T> *head;
	DWORD dwCount;
};

template <class T>
bool Clist<T>::Remove(T* tElement)
{

	if (head == NULL)
		return NULL;
	if (head->Element() == tElement)
	{
		CNode<T> *tmp = head;
		head = head->Next();
		delete tmp;
		this->dwCount--;
		return true;
	}
	CNode <T>* phead = this->head;
	while (phead->Next() != NULL)
	{
		if (phead->Element() == tElement)
		{
			phead->Next() = phead->Next()->Next();
			delete phead->Next();
			dwCount--;
			return false;
		}
		phead = phead->Next();
	}
	return false;
}

template <class T>
void Clist<T>::Insert(T* tElement)
{
	dwCount++;
	if (head == NULL)
	{
		head = new CNode<T>(tElement);
		return;
	}
	CNode<T> *tmp = head;
	head = new CNode<T>(tElement);
	head->Next() = tmp;
}

template <class T>
void Clist<T>::Append(CNode<T>*& node, T* tElement)
{
	if (node == NULL)
	{
		dwCount++;
		node = new CNode<T>(tElement);
		return;
	}
	Append(node->Next(), tElemet);
}

#endif
