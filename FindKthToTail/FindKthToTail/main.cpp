//
//  main.cpp
//  FindKthToTail
//
//  Created by wjl on 16/2/6.
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


//找到倒数k
ListNode* FindKthToTail(ListNode* pListNode, int k){
    
    if (pListNode == NULL || k <= 0) {
        return NULL;
    }
    
    ListNode* pHead = pListNode;
    ListNode* pBehind = NULL;
    
    for (int i=0 ; i < k-1 ; i++) {
        
        if (pHead->m_pNext != NULL) {
            pHead = pHead->m_pNext;
        }
        else{
            return NULL;
        }
    }
    
    pBehind = pListNode;
    while (pHead->m_pNext != NULL) {
        pHead = pHead->m_pNext;
        pBehind = pBehind->m_pNext;
    }
    
    return pBehind;
    
}

int main(int argc, const char * argv[]) {
    
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
    
    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    
    ListNode* pNode =  FindKthToTail(pNode1, 7);
    if(pNode == NULL)
    {
        printf("The node is NULL\n");
    }
    else
    {
        printf("The key in node is %d.\n", pNode->m_nValue);
        
    }
    return  0;
    
}
