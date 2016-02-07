//
//  main.cpp
//  MergeSortedList
//
//  Created by wjl on 16/2/7.
//  Copyright © 2016年 Martin. All rights reserved.
//


#include <stdio.h>
#include <iostream>
#include <exception>
#include <stdlib.h>

using namespace std;

struct ListNode{
    int m_nValue;
    ListNode* m_pNext;
};
//组建链表

ListNode* CreateListNode(int value){
    
    ListNode* pNode = new ListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = NULL;
    
    return pNode;
}


void ConnectListNodes(ListNode* pCurrent, ListNode* pNext){
    
    if (pCurrent == NULL) {
        printf("error");
        exit(1);
    }
    
    pCurrent->m_pNext = pNext;
}

void DestroyList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        pHead = pHead->m_pNext;
        delete pNode;
        pNode = pHead;
    }
}

//合并排序的链表
ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
    
    if (pHead1 == NULL) {
        return pHead2;
    }
    else if (pHead2 == NULL){
        return pHead1;
    }
    
    ListNode* pMergeHead = NULL;
    
    if (pHead1->m_nValue < pHead2->m_nValue) {
        pMergeHead = pHead1;
        pMergeHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
    }
    else{
        pMergeHead = pHead2;
        pMergeHead->m_pNext = Merge(pHead1, pHead2->m_pNext);
    }
    
    return pMergeHead;
    
}

int main(int argc, const char * argv[]) {
    
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(3);
    ListNode* pNode3 = CreateListNode(5);
    
    ListNode* pNode4 = CreateListNode(2);
    ListNode* pNode5 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(6);
    ListNode* pNode7 = CreateListNode(7);
    
    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    
    ListNode* pMergeHead = Merge(pNode1, pNode4);
    
    while (pMergeHead!=NULL) {
        printf("The key in node is %d.\n", pMergeHead->m_nValue);
        pMergeHead = pMergeHead->m_pNext;
    }
    
    DestroyList(pMergeHead);
    
    return  0;
    
}
