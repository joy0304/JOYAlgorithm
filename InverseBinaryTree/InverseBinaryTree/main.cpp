//
//  main.cpp
//  InverseBinaryTree
//
//  Created by wjl on 16/2/21.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

struct BinaryTree{
    int m_Value;
    BinaryTree* m_pLeft;
    BinaryTree* m_pRight;
};

BinaryTree* CreateNodes(int value){
    
    BinaryTree* node = new BinaryTree();
    node->m_Value = value;
    node->m_pLeft = NULL;
    node->m_pRight = NULL;
    
    return node;
}
void ConnectNodes(BinaryTree* root,BinaryTree* left, BinaryTree* right){
    
    if (root!=NULL) {
        
        root->m_pRight = right;
        root->m_pLeft = left;
    }

    
    
}
void PrintTree(BinaryTree* pRoot)
{
    printf("%d\n",pRoot->m_Value);
    
    if(pRoot != NULL)
    {
        if(pRoot->m_pLeft != NULL)
            PrintTree(pRoot->m_pLeft);
        
        if(pRoot->m_pRight != NULL)
            PrintTree(pRoot->m_pRight);
    }
}

BinaryTree* inverseBinaryTree(BinaryTree* node){
    
    if (node==NULL) {
        return node;
    }
    
    BinaryTree* temp = node->m_pLeft;
    node->m_pLeft = inverseBinaryTree(node->m_pRight);
    node->m_pRight = inverseBinaryTree(temp);
    
    return node;
    
}

int main(){
    
    BinaryTree* node1 = CreateNodes(1);
    BinaryTree* node2 = CreateNodes(2);
    BinaryTree* node3 = CreateNodes(3);
    BinaryTree* node4 = CreateNodes(4);
    BinaryTree* node5 = CreateNodes(5);
    BinaryTree* node6 = CreateNodes(6);
    
    
    ConnectNodes(node1,node2,node3);
    ConnectNodes(node2,node4,node5);
    ConnectNodes(node3,node6,NULL);
    
    PrintTree(inverseBinaryTree(node1));
    
    return 0;
}