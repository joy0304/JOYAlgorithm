//
//  main.cpp
//  FirstCommonNodes
//
//  Created by wjl on 16/2/18.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <exception>
#include <stdlib.h>
#include <stack>
using namespace std;

struct ListNode{
    int Value;
    ListNode* pNext;
};

//构建链表
//
//ListNode* CreateListNode(int value){
//    
//    ListNode* pNode = new ListNode();
//    pNode->m_nValue = value;
//    pNode->m_pNext = NULL;
//    
//    return pNode;
//}
//
//void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
//{
//    if(pCurrent == NULL)
//    {
//        printf("Error to connect two nodes.\n");
//        exit(1);
//    }
//    
//    pCurrent->m_pNext = pNext;
//}
////算法
//
int GetListLength(ListNode* pHead){
    
    int nLength = 0;
    ListNode* pNode = pHead;
    while (pNode!=NULL) {
        nLength++;
        pNode = pNode->pNext;
    }
    return nLength;
    
}

ListNode* FindFirstCommonNode(ListNode* Phead1, ListNode* pHead2){
    
    int nLength1 = GetListLength(Phead1);
    int nLength2 = GetListLength(pHead2);
    int nlengthGap = nLength1 - nLength2;
    
    ListNode* pNode1 = Phead1;
    ListNode* pNode2 = pHead2;
    
    ListNode* pListLong = NULL;
    ListNode* pListShort = NULL;
    
    if (nlengthGap>=0) {
        pListLong = pNode1;
        pListShort = pNode2;
    }
    else{
        pListLong = pNode2;
        pListShort = pNode1;
        nlengthGap = -nlengthGap;
    }
    
    for(int i=0; i<nlengthGap;i++){
        pListLong = pListLong->pNext;
    }
    
    while (pListLong!=NULL && pListShort!=NULL && pListLong!=pListShort) {
        pListLong = pListLong->pNext;
        pListShort = pListShort->pNext;
    }
    
    ListNode* pFirstCommonNode = pListLong;
    
    return pFirstCommonNode;
}

//int main(int argc, const char * argv[]) {
//    
//    ListNode* pNode1 = CreateListNode(1);
//    ListNode* pNode2 = CreateListNode(2);
//    ListNode* pNode3 = CreateListNode(3);
//    ListNode* pNode4 = CreateListNode(4);
//    ListNode* pNode5 = CreateListNode(5);
//    
//    ConnectListNodes(pNode1, pNode2);
//    ConnectListNodes(pNode2, pNode3);
//    ConnectListNodes(pNode3, pNode4);
//    ConnectListNodes(pNode4, pNode5);
//    
//    ListNode* result = FindFirstCommonNode(pNode1,pNode3);
//    
//    if(result != NULL)
//    {
//        printf("%d\n", result->m_nValue);
//    }
//    return  0;
//    
//}
//
//
//
//
