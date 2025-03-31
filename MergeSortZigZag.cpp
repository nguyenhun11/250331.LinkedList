
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


/////////////////////
NODE* CreateNode(int x) {
	NODE* p;
	p = new NODE;
	//if (p == NULL)
    //		exit(1);

	p->info = x;
	p->pNext = NULL;
	return p;
}
void AddTail(LIST &L, NODE* p) {
	if (L.pHead == NULL) {
		L.pHead = p;
		L.pTail = L.pHead;
	}
	else {
		L.pTail->pNext = p;
		L.pTail=p;
    }
}
void CreateEmptyList(LIST &L) {
	L.pHead = NULL;
	L.pTail = NULL;
}
void CreateList(LIST &L) {
	NODE* p;
	int x, n;
    cin >> n; // Số lượng phần tử của danh sách
	while (n-->0) {
		cin >> x;
		p = CreateNode(x);
		AddTail(L, p);
	}
}
void PrintList(NODE*Head)
{
    if (Head == nullptr)
    {
        cout << "Empty List." << endl;
    }
    else
    {
        NODE *ptr = Head;
        while (ptr != nullptr)
        {
            cout << ptr->info << " ";
            ptr = ptr->pNext;
        }
        cout << endl;
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
void Partition(LIST &L, LIST &L1, LIST &L2)
{
    if (L.pHead == nullptr)
        return;
    bool AddTo1 = true;
    while (L.pHead != nullptr)
    {
        NODE *curr = SeparateHead(L);
        if (AddTo1)
        {
            AddTail(L1, curr);
        }
        else //if (curr->info > pivot->info)
        {
            AddTail(L2, curr);
        }
        AddTo1 = !AddTo1;
    }
}
void Merge(LIST& L, LIST& L1, LIST& L2) {
    CreateEmptyList(L); 

    while (L1.pHead != nullptr && L2.pHead != nullptr) {
        if (L1.pHead->info < L2.pHead->info) {
            AddTail(L, SeparateHead(L1));
        } else {
            AddTail(L, SeparateHead(L2));
        }
    }

    while (L1.pHead != nullptr) {
        AddTail(L, SeparateHead(L1));
    }

    while (L2.pHead != nullptr) {
        AddTail(L, SeparateHead(L2));
    }
}



void mergesort_ascending(LIST&L){
    if (L.pHead == nullptr || L.pHead == L.pTail)
        return;
    LIST L1, L2;
    CreateEmptyList(L1);
    CreateEmptyList(L2);

    Partition(L,L1,L2);
    mergesort_ascending(L1);
    mergesort_ascending(L2);
    Merge(L,L1,L2);
}
void Swap(int &a, int&b){
    a=a^b;
    b=a^b;
    a=a^b;
}
void ZigZagList(LIST&L){
    if (L.pHead==nullptr||L.pHead==L.pTail ||L.pHead->pNext==L.pTail) return;
    mergesort_ascending(L);
    NODE*ptr = L.pHead->pNext;
    while(ptr!=nullptr&&ptr->pNext!=nullptr){
        Swap(ptr->info, ptr->pNext->info);
        ptr=ptr->pNext->pNext;
    }
}



/////////////////////



int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);

	ZigZagList(L);

    PrintList(L.pHead);

    return 0;
}
