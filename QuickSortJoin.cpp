
#include <iostream>
using namespace std;

// Cấu trúc của một node
struct NODE {
	int info;
	NODE* pNext;
};
// Cấu trúc của một DSLK
struct LIST {
	NODE* pHead;
	NODE* pTail;
};

////////////////

void CreateEmptyList(LIST &L)
{
    L.pHead = nullptr;
    L.pTail = nullptr;
}
NODE *CreateNode(int a)
{
    NODE *p = new NODE;
    p->info = a;
    p->pNext = nullptr;
    return p;
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
void PrintList(LIST &L)
{
    if (L.pHead == nullptr)
    {
        cout << "Empty List." << endl;
    }
    else
    {
        NODE *ptr = L.pHead;
        while (ptr != nullptr)
        {
            cout << ptr->info << " ";
            ptr = ptr->pNext;
        }
        cout << endl;
    }
}
void AddTail(LIST &L, NODE *p)
{
    if (L.pHead == nullptr)
    {
        L.pHead = p;
        L.pTail = p;
    }
    else
    {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}
void Join(LIST&L, LIST&L1,NODE*pivot, LIST&L2){
    L.pHead = L1.pHead;
    L.pTail = L1.pTail;
    AddTail(L,pivot);
    L.pTail->pNext = L2.pHead;
    L.pTail = L2.pTail;
    CreateEmptyList(L1);
    CreateEmptyList(L2);
}




//////////////////


int main() {
    LIST L, L1, L2;

	int x;
	NODE *pivot;

	CreateEmptyList(L);
	CreateEmptyList(L1);
	CreateEmptyList(L2);

	CreateList(L1);
	cin >> x;
	pivot=CreateNode(x);
	CreateList(L2);


	Join(L, L1, pivot, L2);
	PrintList(L);

    return 0;
}
