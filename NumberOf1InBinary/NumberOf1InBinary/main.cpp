//
//  main.cpp
//  NumberOf1InBinary
//
//  Created by wjl on 16/2/3.
//  Copyright © 2016年 Martin. All rights reserved.
//


#include <stdio.h>
#include <iostream>
#include <exception>

using namespace std;

int NumberOf1(int n){
    int count = 0;
    int flag = 1;
    while (flag) {
        
        if (n & flag)
            count++;
        
        flag = flag << 1;
        //printf("%d \n",flag);
    }
    return count;
}


int NumberOf2(int n){
    int count = 0;
    
    while (n) {
        ++count;
        
        n = (n-1) & n;
    }
    
    return  count;
}

int main(int argc, const char * argv[]) {
    
    int i = NumberOf1(0x7FFFFFFF);
    int j = NumberOf2(12);
    
    std::cout<< i <<std::endl;
    std::cout<< j <<std::endl;
    return  0;
    
}
