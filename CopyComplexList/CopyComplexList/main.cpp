//
//  main.cpp
//  CopyComplexList
//
//  Created by wjl on 16/2/10.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <iostream>

struct ComplexListNode{
    
    int m_nValue;
    ComplexListNode* m_pNext;
    ComplexListNode* m_pSibling;
};
//创建链表
ComplexListNode* CreateNode(int nValue)
{
    ComplexListNode* pNode = new ComplexListNode();
    
    pNode->m_nValue = nValue;
    pNode->m_pNext = NULL;
    pNode->m_pSibling = NULL;
    
    return pNode;
}

void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling)
{
    if(pNode != NULL)
    {
        pNode->m_pNext = pNext;
        pNode->m_pSibling = pSibling;
    }
}

void PrintList(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode != NULL)
    {
        printf("The value of this node is: %d.\n", pNode->m_nValue);
        
        if(pNode->m_pSibling != NULL)
            printf("The value of its sibling is: %d.\n", pNode->m_pSibling->m_nValue);
        else
            printf("This node does not have a sibling.\n");
        
        printf("\n");
        
        pNode = pNode->m_pNext;
    }
}

//具体算法
void CloneNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode != NULL)
    {
        ComplexListNode* pCloned = new ComplexListNode();
        pCloned->m_nValue = pNode->m_nValue;
        pCloned->m_pNext = pNode->m_pNext;
        pCloned->m_pSibling = NULL;
        
        pNode->m_pNext = pCloned;
        
        pNode = pCloned->m_pNext;
    }
}

void ConnectSiblingNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode != NULL)
    {
        ComplexListNode* pCloned = pNode->m_pNext;
        if(pNode->m_pSibling != NULL)
        {
            pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
        }
        
        pNode = pCloned->m_pNext;
    }
}

ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    ComplexListNode* pClonedHead = NULL;
    ComplexListNode* pClonedNode = NULL;
    
    if(pNode != NULL){
        pClonedHead = pClonedNode = pNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    
    while(pNode != NULL){
        pClonedNode->m_pNext = pNode->m_pNext;
        pClonedNode = pClonedNode->m_pNext;
        
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    
    return pClonedHead;
}

ComplexListNode* Clone(ComplexListNode* pHead){
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}

int main(int argc, const char * argv[]) {
    
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);
    
    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, NULL);
    BuildNodes(pNode4, pNode5, pNode2);
    
    
    printf("The original list is:\n");
    PrintList(pNode1);
    
    ComplexListNode* pClonedHead = Clone(pNode1);
    
    printf("The cloned list is:\n");
    PrintList(pClonedHead);
    
    //std::cout << "Hello, World!\n";
    return 0;
}
