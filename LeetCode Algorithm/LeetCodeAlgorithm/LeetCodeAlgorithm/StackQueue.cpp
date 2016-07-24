//
//  StackQueue.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/7/24.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <stack>
using namespace std;

template <typename T>
class CQueue {
public:
    void add(T value);
    T peek();
    T poll();
    
private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T> void CQueue<T>::add(T value) {
    
    stack1.push(value);
}

template <typename T> T CQueue<T>::peek() {

    if (stack2.size() < 1) {
        while (stack1.size() > 0) {
            T value = stack1.top();
            stack2.push(value);
            stack1.pop();
        }
    }
    if (stack1.size() == 0) {
        return NULL;
    }
    T head = stack2.pop();
    return head;
    
}