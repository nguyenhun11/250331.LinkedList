
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
void Partition(LIST &L, LIST &L1, NODE *&pivot, LIST &L2)
{
    if (L.pHead == nullptr)
        return;
    pivot = SeparateHead(L);

    if (L.pHead == nullptr) return;
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
void Join(LIST& L, LIST& L1, NODE* pivot, LIST& L2) {
    if (L1.pHead == nullptr) {
        L.pHead = pivot;
    } else {
        L.pHead = L1.pHead;
        L1.pTail->pNext = pivot;
    }

    pivot->pNext = L2.pHead;

    if (L2.pTail != nullptr) {
        L.pTail = L2.pTail;
    } else {
        L.pTail = pivot;
    }
}


void quicksort_ascending(LIST&L){
    if (L.pHead == nullptr || L.pHead == L.pTail)
        return;
    NODE*pivot;
    LIST L1, L2;
    CreateEmptyList(L1);
    CreateEmptyList(L2);

    Partition(L,L1,pivot,L2);
    quicksort_ascending(L1);
    quicksort_ascending(L2);
    Join(L,L1,pivot,L2);
}
void Swap(int &a, int&b){
    a=a^b;
    b=a^b;
    a=a^b;
}
void ZigZagList(LIST&L){
    if (L.pHead==nullptr||L.pHead==L.pTail ||L.pHead->pNext==L.pTail) return;
    quicksort_ascending(L);
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
