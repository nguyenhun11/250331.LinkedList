#include <iostream>
using namespace std;
struct NODE
{
    int val;
    NODE *next;
    NODE()
    {
        val = 0;
        next = nullptr;
    }
    NODE(int a)
    {
        val = a;
        next = nullptr;
    }
};
struct LIST
{
    NODE *pHead;
    NODE *pTail;
};

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
            L.pHead = new NODE(n);
            L.pTail = L.pHead;
        }
        else
        {
            L.pTail->next = new NODE(n);
            L.pTail = L.pTail->next;
        }
        cin >> n;
    }
}
void PrintList(LIST &L)
{
    if (L.pHead == nullptr)
    {
        cout << "Empty List.";
    }
    else
    {
        NODE *ptr = L.pHead;
        while (ptr != nullptr)
        {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
    }
}
void add_after_k_th(LIST &L, int Y, int k)
{
    NODE *newNode = new NODE(Y);
    NODE *ptr = L.pHead;
    if (L.pHead == nullptr)
    {
        if (k == 0)
        {
            L.pHead = newNode;
            L.pTail = newNode;
            return;
        }
        return;
    }
    else if(k==0){
        newNode->next = ptr;
        L.pHead=newNode;
    }
    else
    {
        
        while (k > 1 && ptr != nullptr)
        {
            // cout << k <<" " << ptr->val<<endl;
            ptr = ptr->next;
            k--;
        }
        if (k == 1 && ptr->next != nullptr)
        {
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
        else if (k == 1 && ptr->next == nullptr)
        {
            ptr->next = newNode;
            L.pTail = newNode;
        }
    }
}

int main()
{
    LIST L;
    int k, Y;

    CreateEmptyList(L);

    CreateList(L);

    std::cin >> k >> Y;
    add_after_k_th(L, Y, k);

    PrintList(L);

    return 0;
}
