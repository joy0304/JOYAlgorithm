//
//  main.cpp
//  ReverseList
//
//  Created by wjl on 16/2/6.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <iostream>


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

//反转链表
ListNode* ReverseList(ListNode* pHead){
    
    ListNode* pReverseHead = NULL;
    ListNode* pNode = pHead;
    ListNode* pPrevNode = NULL;
    
    while (pNode != NULL) {
        
        //先记住下一个结点是谁，防止后面无法与前面相连
        ListNode* pNext = pNode->m_pNext;
        
        if (pNext == NULL) {
            
            pReverseHead = pNode;
        }
        
        pNode->m_pNext = pPrevNode;
        pPrevNode = pNode;
        pNode = pNext;
        
    }
    return pReverseHead;
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
    
    
    ListNode* temp =  ReverseList(pNode1);
    ListNode* temp2 = ReverseList(NULL);
    
    if (temp2 == NULL) {
        printf("null \t");
    }
    else{
        printf("%d \t",temp2->m_nValue);
    }
    
    
    return  0;
    
}
