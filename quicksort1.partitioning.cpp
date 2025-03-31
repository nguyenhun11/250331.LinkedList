
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

///////
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
NODE *SeparateHead(LIST &L)
{
    if (L.pHead == nullptr)
        return nullptr;

    NODE *head = L.pHead;
    L.pHead = L.pHead->pNext;
    head->pNext = nullptr;
    return head;
}
void Partition(LIST &L, LIST &L1, NODE *&pivot, LIST &L2)
{
    if (L.pHead == nullptr)
        return;
    pivot = SeparateHead(L);

    
    while (L.pHead != nullptr)
    {
        NODE *curr = SeparateHead(L);
        if (curr->info <= pivot->info)
        {
            AddTail(L1, curr);
        }
        else //if (curr->info > pivot->info)
        {
            AddTail(L2, curr);
        }
    }
}

///////

int main()
{
    LIST L, L1, L2;
    NODE *pivot;

    CreateEmptyList(L);
    CreateEmptyList(L1);
    CreateEmptyList(L2);
    CreateList(L);

    if (L.pHead == NULL)
    {
        cout << "Empty List.";
        return 0;
    }

    Partition(L, L1, pivot, L2);

    cout << pivot->info << endl;
    PrintList(L1);
    PrintList(L2);
    PrintList(L);

    return 0;
}
