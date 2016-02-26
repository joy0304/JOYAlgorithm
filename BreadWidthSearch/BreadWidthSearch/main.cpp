//
//  main.cpp
//  BreadWidthSearch
//
//  Created by wjl on 16/2/26.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

void BreadWidthSearch(BinaryTreeNode* root){
    
    queue<BinaryTreeNode*> queue;
    queue.push(root);
    BinaryTreeNode* pNode = root;
    
    while (!queue.empty()) {
        
        printf("%d\n",queue.front()->m_nValue);
        pNode = queue.front();
        queue.pop();
        
        if (pNode->m_pLeft!=NULL) {
            queue.push(pNode->m_pLeft);
        }
        if (pNode->m_pRight!=NULL) {
            queue.push(pNode->m_pRight);
        }
    }
    
    
}
