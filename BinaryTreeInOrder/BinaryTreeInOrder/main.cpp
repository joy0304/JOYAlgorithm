//
//  main.cpp
//  BinaryTreeInOrder
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

void InOrderRecursion(BinaryTreeNode* subTree){
    
    if (subTree!=NULL) {
        InOrderRecursion(subTree->m_pLeft);
        printf("%d\n",subTree->m_nValue);
        InOrderRecursion(subTree->m_pRight);
    }
    
}

void Visit(BinaryTreeNode* pNode){
    printf("%d\n",pNode->m_nValue);
}
//当结点右侧为空，并且栈为空时中止
void InOrderIteration(BinaryTreeNode* subTree){
    stack<BinaryTreeNode*> stack;
    BinaryTreeNode* pNode = subTree;
    
    do{
        while (pNode!=NULL) {
            stack.push(pNode);
            pNode = pNode->m_pLeft;
        }
        if (!stack.empty()) {
            Visit(stack.top());
            pNode = stack.top()->m_pRight;
            stack.pop();
        }
    }while (pNode!=NULL || !stack.empty());

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
    
    InOrderRecursion(root1);
    InOrderIteration(root1);
    return  0;
    
}
