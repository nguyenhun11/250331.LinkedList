
#include <iostream>
#include <cstdlib>
#include <ctime>
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

NODE* CreateNode(int x) {
	NODE* p;
	p = new NODE;
	//if (p == NULL)
    //		exit(1);

	p->info = x;
	p->pNext = NULL;
	return p;
}

void CreateEmptyList(LIST &L) {
	L.pHead = NULL;
	L.pTail = NULL;
}


//////
void CreateList(LIST &L)
{
	int size;
	cin >> size;
    int i = 0;
	while (i<size)
	{
        int n;
        cin >> n;
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
        i++;
	}
}

void PrintList(NODE* head)
{
    if (head == nullptr)
    {
        cout << "Empty List.";
    }
    else
    {
        NODE *ptr = head;
        while (ptr != nullptr)
        {
            cout << ptr->info << " ";
            ptr = ptr->pNext;
        }
    }
}
 NODE* SeparateHead(LIST& L){
    if (L.pHead==nullptr) return nullptr;

    NODE* head = L.pHead;
    L.pHead = L.pHead->pNext;
    return head;
 }


//////



int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    NODE*p=SeparateHead(L);
	if( p!=NULL) cout << p->info << endl;
    PrintList(L.pHead);

    return 0;
}
