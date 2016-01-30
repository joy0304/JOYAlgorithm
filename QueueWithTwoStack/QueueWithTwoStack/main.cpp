//
//  main.cpp
//  QueueWithTwoStack
//
//  Created by wjl on 16/1/30.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

template <typename T> class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);
    
    void appendTail(const T& node);
    
    T deleteHead();
    
private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T> CQueue<T>::CQueue(void){}

template <typename T> CQueue<T>::~CQueue(void){}

template<typename T> void CQueue<T>::appendTail(const T& element){
    stack1.push(element);
}

template<typename T> T CQueue<T>::deleteHead(){
    if(stack2.size()<= 0)
    {
        while(stack1.size()>0)
        {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }

    T head = stack2.top();
    stack2.pop();
    
    return head;
}


int main(int argc, const char * argv[]) {
    
    CQueue<char> queue;
    
    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');
    
    
    char head = queue.deleteHead();
    std::cout<< head <<std::endl;
    
    return  0;
    
}
