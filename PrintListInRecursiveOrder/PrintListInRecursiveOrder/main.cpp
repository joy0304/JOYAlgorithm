//
//  main.cpp
//  PrintListInRecursiveOrder
//
//  Created by wjl on 16/1/29.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <iostream>

struct ListNode{
    int m_nValue;
    ListNode* m_pNext;
    
};
//递归正是利用了栈结构
void PrintListInRecursiveOrder(ListNode* pHead){
    
    if (pHead != NULL) {
        if (pHead->m_pNext != NULL) {
            
            PrintListInRecursiveOrder(pHead->m_pNext);
        }
        printf("%d\t",pHead->m_nValue);
    }
}

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



int main(int argc, const char * argv[]) {
    
    
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    
    ConnectListNode(pNode1,pNode2);
    ConnectListNode(pNode2,pNode3);
    
    PrintListInRecursiveOrder(pNode1);
    
    return 0;
}
