//
//  minDepth.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/6/28.
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

int minDepth(BinaryTreeNode* root) {
    if( root == NULL ) return 0;
    int rDepth = minDepth( root->rightNode ) + 1;
    int lDepth = minDepth( root->leftNode ) + 1;
    if( root->rightNode == NULL )
    {
        return lDepth;
    }
    else if( root->leftNode == NULL )
    {
        return rDepth;
    }
    else
    {
        return rDepth < lDepth ? rDepth : lDepth;
    }
    
}