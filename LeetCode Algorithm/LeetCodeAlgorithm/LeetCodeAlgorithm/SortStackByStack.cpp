//
//  SortStackByStack.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/7/25.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <stack>
using namespace std;

void sortStackByStack (stack<int> sStack) {
    
    stack<int> helpStack;
    while (sStack.size()) {
        int popValue = sStack.top();
        sStack.pop();
        if (helpStack.size() == 0 || popValue > helpStack.top()) {
            helpStack.push(popValue);
        }
        else {
            while (helpStack.size() > 0) {
                int value = helpStack.top();
                helpStack.pop();
                sStack.push(value);
            }
        }
    }
    while (helpStack.size() > 0 ) {
        sStack.push(helpStack.top());
        helpStack.pop();
    }
    
    
}