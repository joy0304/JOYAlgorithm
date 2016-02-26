//
//  main.cpp
//  InverseList
//
//  Created by wjl on 16/2/26.
//  Copyright © 2016年 Martin. All rights reserved.
//
#include <iostream>

using namespace std;

struct ListNode{
    int m_nValue;
    ListNode* m_pNext;
    
};

//创建链表元素
ListNode* CreateListNode(int value){
    
    ListNode* pNode = new ListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = NULL;
    return pNode;
}

//添加链表元素
void ConnectListNode(ListNode* pCurrent, ListNode* pNext){
    
    if(pCurrent == NULL)
    {
        printf("Error\n");
        exit(1);
    }
    pCurrent->m_pNext = pNext;
}

ListNode* inverseList(ListNode* head){
    
    if (head == NULL) {
        return NULL;
    }
    
    ListNode* prev = NULL;
    ListNode* pNode = head;
    ListNode* nNode = NULL;
    while (pNode!=NULL) {
        
        nNode = pNode->m_pNext;
        pNode->m_pNext = prev;
        prev = pNode;
        pNode = nNode;
        
    }
    return prev;
    
    
}


int main(){
    
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    
    ConnectListNode(pNode1,pNode2);
    ConnectListNode(pNode2,pNode3);
    
    inverseList(pNode1);
    for (; pNode3!=NULL; ) {
        printf("%d",pNode3->m_nValue);
        pNode3 = pNode3->m_pNext;
    }
    return 0;
}
