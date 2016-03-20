//
//  main.cpp
//  TreeDepth
//
//  Created by wjl on 16/3/20.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <iostream>

struct BinaryTree{
    
    int value;
    BinaryTree* pLeft;
    BinaryTree* pRight;
};

int TreeDepth(BinaryTree* pRoot){
    
    if (pRoot == NULL) {
        return 0;
    }
    
    int leftDepth = TreeDepth(pRoot->pLeft);
    int rightDepth = TreeDepth(pRoot->pRight);
    
    return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}
