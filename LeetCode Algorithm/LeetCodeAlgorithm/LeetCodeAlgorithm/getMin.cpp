//
//  getMin.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/7/24.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <stack>
using namespace std;

template <typename T>
class MinStack {
public:
    void push(T value);
    void pop();
    T getMin();
    
private:
    stack<T> dataStack;
    stack<T> minStack;
};

template <typename T> void MinStack<T>::push(T value) {
    dataStack.push(value);
    if (value < minStack.top() || minStack.size() == 0) {
        minStack.push(value);
    }
    else {
        minStack.push(minStack.top());
    }
}

template <typename T> void MinStack<T>::pop() {
    if (dataStack.size() > 0 && minStack.size() > 0) {
        dataStack.pop();
        minStack.pop();
    }
}

template <typename T> T MinStack<T>::getMin() {
    if (minStack.size() > 0) {
        return minStack.top();
    }
    return NULL;
}
