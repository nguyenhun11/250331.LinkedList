
#include <iostream>
using namespace std;

// Cấu trúc của một node
struct NODE
{
	int info;
	NODE *pNext;
};
// Cấu trúc của một DSLK
struct LIST
{
	NODE *pHead;
	NODE *pTail;
};

/////
NODE *CreateNode(int a)
{
	NODE *ptr = new NODE;
	ptr->info = a;
	ptr->pNext = nullptr;
	return ptr;
}
void CreateEmptyList(LIST &L)
{
	L.pHead = nullptr;
	L.pTail = nullptr;
}
void CreateList(LIST &L)
{
	int n;
	cin >> n;
	while (n != -1)
	{
		if (L.pHead == nullptr)
		{
			L.pHead = CreateNode(n);
			L.pTail = L.pHead;
		}
		else
		{
			L.pTail->pNext = CreateNode(n);
			L.pTail = L.pTail->pNext;
		}
		cin >> n;
	}
}
void ReverseList(NODE *&head)
{
	if (head == nullptr || head->pNext == nullptr)
	{
		return;
	}
	else
	{
		NODE *curr = head;
		NODE *prev = nullptr;
		NODE *next;
		while (curr != nullptr)
		{
			next = curr->pNext;
			curr->pNext = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}
}

int searchXget_nth_node_from_tail(NODE *ptr, int k)
{
	if (k==0) return -1;
	ReverseList(ptr);
	int i = 1;
	while (i < k && ptr != nullptr)
	{
		ptr = ptr->pNext;
		i++;
	}
	if (ptr != nullptr)
		return ptr->info;
	else
		return -1;
}

/////

int main()
{
	LIST L;
	int k;
	CreateEmptyList(L);
	CreateList(L);

	std::cin >> k;
	cout << searchXget_nth_node_from_tail(L.pHead, k);

	return 0;
}
