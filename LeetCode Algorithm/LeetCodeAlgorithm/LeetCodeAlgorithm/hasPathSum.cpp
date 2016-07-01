//
//  hasPathSum.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/6/28.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stack>
using namespace std;

struct BinaryTreeNode {
    int value;
    BinaryTreeNode *leftNode;
    BinaryTreeNode *rightNode;
};
bool hasPathSum(BinaryTreeNode* root, int sum) {
    
    if (root == NULL) {
        return false;
    }
    if (root->value == sum && root->leftNode == NULL && root->rightNode == NULL) {
        return true;
    }
    return (hasPathSum(root->leftNode, sum-root->value) || hasPathSum(root->rightNode, sum-root->value));
    
}