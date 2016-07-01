//
//  IsBalanced.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/6/29.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
using std::abs;

struct BinaryTreeNode {
    int value;
    BinaryTreeNode *leftNode;
    BinaryTreeNode *rightNode;
};

int getHeight(BinaryTreeNode *root){
    
    if (root == NULL) {
        return 0;
    }
    return (max(getHeight(root->rightNode),getHeight(root->leftNode)) + 1);
}

bool isBalanced(BinaryTreeNode* root) {
    
    if (root == NULL) {
        return true;
    }
    return (isBalanced(root->leftNode) && isBalanced(root->rightNode) && abs(getHeight(root->leftNode) - getHeight(root->rightNode)) <= 1);
}