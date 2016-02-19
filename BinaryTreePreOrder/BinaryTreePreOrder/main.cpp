//
//  main.cpp
//  BinaryTreePreOrder
//
//  Created by wjl on 16/2/19.
//  Copyright © 2016年 Martin. All rights reserved.
//
#include <iostream>
#include <stack>
using namespace std;

struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

BinaryTreeNode* CreateBinaryTreeNode(int Value){
    
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->m_nValue = Value;
    pNode->m_pLeft = NULL;
    pNode->m_pRight = NULL;
    
    return pNode;
    
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != NULL)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
    }
}

void DestroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot != NULL)
    {
        BinaryTreeNode* pLeft = pRoot->m_pLeft;
        BinaryTreeNode* pRight = pRoot->m_pRight;
        
        delete pRoot;
        pRoot = NULL;
        
        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

//前序
void PreOrder(BinaryTreeNode* subtree){
    
    stack<BinaryTreeNode*> sta;
    BinaryTreeNode* pNode = subtree;
    sta.push(pNode);
    while (!sta.empty()) {
        printf("%d\n",sta.top()->m_nValue);
        pNode = sta.top();
        sta.pop();
        if (pNode->m_pRight!=NULL) {
            sta.push(pNode->m_pRight);
        }
        if(pNode->m_pLeft!=NULL){
            sta.push(pNode->m_pLeft);
        }
        
    }
    
}

int main(int argc, const char * argv[]) {
    
    BinaryTreeNode* root1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* root2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* root3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* root4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* root5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* root6 = CreateBinaryTreeNode(6);
    
    ConnectTreeNodes(root1, root2, root3);
    ConnectTreeNodes(root2, root4, root5);
    ConnectTreeNodes(root3, root6, NULL);

    PreOrder(root1);
    DestroyTree(root1);
    return  0;
    
}
