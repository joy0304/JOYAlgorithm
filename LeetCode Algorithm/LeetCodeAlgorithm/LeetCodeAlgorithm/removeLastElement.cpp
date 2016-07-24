//
//  removeLastElement.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/7/24.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <stack>
using namespace std;

int removeLastElement(stack<int> stack) {

    int result = stack.top();
    stack.pop();
    if (stack.size() == 0) {
        return result;
    }
    else {
        int last = removeLastElement(stack);
        stack.push(result);
        return last;
    }
    
}