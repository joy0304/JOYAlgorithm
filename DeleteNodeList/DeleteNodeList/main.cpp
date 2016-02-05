//
//  main.cpp
//  DeleteNodeList
//
//  Created by wjl on 16/2/5.
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
//构建链表

ListNode* CreateListNode(int value){
    
    ListNode* pNode = new ListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = NULL;
    
    return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
    if(pCurrent == NULL)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }
    
    pCurrent->m_pNext = pNext;
}

void PrintList(ListNode* pHead)
{
    printf("PrintList starts.\n");
    
    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        printf("%d\t", pNode->m_nValue);
        pNode = pNode->m_pNext;
    }
    
    printf("\nPrintList ends.\n");
}


//以下代码是删除结点
void deleteNode(ListNode** pListHead, ListNode* pToBeDeleted){
    
    if (!pListHead || !pToBeDeleted ) {
        return;
    }
    //要删除的不是尾节点
    if (pToBeDeleted->m_pNext != NULL) {
        
        ListNode* pNext = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = pNext->m_nValue;
        pToBeDeleted->m_pNext = pNext->m_pNext;
        
        delete pNext;
        pNext = NULL;
    }
    
    else if (*pListHead == pToBeDeleted){
        
        delete pToBeDeleted;
        pToBeDeleted = NULL;
        *pListHead = NULL;
    }
    else{
        ListNode* pNode = *pListHead;
        while (pNode->m_pNext != pToBeDeleted) {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = NULL;
        delete pToBeDeleted;
        pToBeDeleted = NULL;
        
    }
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
    
    deleteNode(&pNode1, pNode5);
    
    PrintList(pNode1);
    
    return  0;
    
}
