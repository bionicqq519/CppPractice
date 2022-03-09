/*
Author : Nick Lee
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {};
	ListNode(int x) : val(x),next(nullptr) {};
	ListNode(int x, ListNode *tpval) : val(x), next(tpval){}
};

void travelList(ListNode *ptHead)
{
	ListNode *node = ptHead;
	while(node!= nullptr)
	{
		printf("%d ", node->val);
		node = node->next;
	}
	return;
}

void append(ListNode **ppthead, int dVal)
{
	ListNode *cur = *ppthead;
	ListNode *pre = nullptr;
	while(cur != nullptr)
	{
		pre = cur;
		cur = cur->next;
	}
	ListNode *NewNode = new ListNode(dVal);
	
	if(pre)
		pre->next = NewNode;
	else
		*ppthead = NewNode;
		
	return;
}

void appendIndirect(ListNode **pptHead, int dVal)
{
	ListNode **indirect = pptHead;
	while(*indirect)
	{
		indirect = &(*indirect)->next;
	}
	*indirect = new ListNode(dVal);
}

void removeList(ListNode **pptHead, ListNode *target)
{
	ListNode **indirect = pptHead;
	while(*indirect != target)
	{
		indirect = &(*indirect)->next;
	}
	(*indirect) = target->next;
	delete target;
}

int main()
{
    ListNode *pHead = nullptr;
    for(int i=0;i<10;i++)
    	appendIndirect(&pHead, i);
    travelList(pHead);
    printf("\n");
    
    removeList(&pHead, pHead->next->next);
    removeList(&pHead, pHead->next->next->next->next->next->next);
    
    travelList(pHead);
    
    printf("program end\n");
    system("pause");
    return 0;
}

