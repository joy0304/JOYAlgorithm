//
//  main.cpp
//  IsPopOrder
//
//  Created by wjl on 16/2/10.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

bool IsPopOrder(int* pPush, int* pPop, int length){
    
    bool isOrder = false;
    
    if (pPush != NULL && pPop != NULL && length > 0) {
        
        int* nextPush = pPush;
        int* nextPop = pPop;
        
        std::stack<int>stackData;
        
        while (nextPop - pPop < length) {
            
            while (stackData.empty() || stackData.top() != *nextPop) {
                
                if (nextPush - pPush == length) {
                    break;
                }
                
                stackData.push(*nextPush);
                
                nextPush++;
                
            }
            
            if (stackData.top() != *nextPop) {
                break;
            }
            
            stackData.pop();
            
            nextPop++;
            
        }
        
        if (stackData.empty() && nextPop - pPop == length) {
            isOrder = true;
        }
        
    }
    return isOrder;
    
}


int main(){
    
    int length = 5;
    
    int push[5] = {1, 2, 3, 4, 5};
    int pop[5] = {4,5,3,2,1};
    
    bool result = IsPopOrder(push, pop, length);
    
    if(result)
        printf("Passed.\n");
    else
        printf("failed.\n");
    
    return 0;
}



