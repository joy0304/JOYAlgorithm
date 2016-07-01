//
//  BinaryTree.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/6/22.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <stack>
using namespace std;

struct BinaryTreeNode {
    int value;
    BinaryTreeNode *leftNode;
    BinaryTreeNode *rightNode;
};

BinaryTreeNode* createTreeNode(int value) {
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->value = value;
    pNode->leftNode = NULL;
    pNode->rightNode = NULL;
    
    return pNode;
}

void connectTreeNode(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight) {
    
    if (pParent) {
        pParent->leftNode = pLeft;
        pParent->rightNode = pRight;
    }
}

// 二叉树的前序遍历

void preOrder(BinaryTreeNode *pNode) {
    if (pNode) {
        //visit(pNode);
        preOrder(pNode->leftNode);
        preOrder(pNode->rightNode);
    }
}

void preOrderIterator(BinaryTreeNode *tree){
    
    stack<BinaryTreeNode*> stack;
    BinaryTreeNode *pNode = tree;
    stack.push(pNode);
    
    while (!stack.empty()) {
        printf("%d\n",stack.top()->value);
        pNode = stack.top();
        stack.pop();
        
        if (pNode->rightNode != NULL) {
            stack.push(pNode->rightNode);
        }
        if (pNode->leftNode != NULL) {
            stack.push(pNode->leftNode);
        }
    }
    
}

//中序

void inOrder(BinaryTreeNode *tree) {
    
    stack<BinaryTreeNode*> stack;
    BinaryTreeNode *pNode = tree;
    stack.push(pNode);
    while (pNode || !stack.empty()) {
        if (pNode != NULL) {
            stack.push(pNode);
            pNode = pNode->leftNode;
        }
        if (!stack.empty()) {
            pNode = stack.top();
            stack.pop();
            // visit (stack.top());
            pNode = pNode->rightNode;
        }
    }
    
}

//后序


