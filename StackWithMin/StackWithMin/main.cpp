//
//  main.cpp
//  StackWithMin
//
//  Created by wjl on 16/2/9.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stack>
#include <iostream>
#include <stdlib.h>

using namespace std;

template <typename T> class StackWithMin{

public:
    StackWithMin(){}
    ~StackWithMin(){}
    
    //参数为引用，为了增加效率同时防止修改
    void push(const T& value);
    void pop();
    
    T& min();
private:
    std::stack<T> m_data;
    std::stack<T> m_min;
};

template <typename T> void StackWithMin<T>::push(const T& value){
    
    m_data.push(value);
    
    if (m_min.size() == 0 || value < m_min.top()) {
        m_min.push(value);
    }
    else
        m_min.push(m_min.top());
    
}

template <typename T> void StackWithMin<T>::pop(){
    
    m_min.pop();
    m_data.pop();
}

template <typename T> T& StackWithMin<T>::min(){
    
    return m_min.top();
}

int main(){
    
    StackWithMin<int> stack;
    
    stack.push(2);
    stack.push(4);
    stack.push(0);
    stack.push(3);
    
    printf("%d",stack.min());
    
    return 0;
}
