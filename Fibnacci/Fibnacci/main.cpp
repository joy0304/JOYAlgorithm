//
//  main.cpp
//  Fibnacci
//
//  Created by wjl on 16/2/2.
//  Copyright © 2016年 Martin. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <exception>

using namespace std;

//递归实现 复杂度为 n的指数
long Fibonacci(int n){
    if (n<=0) {
        return 0;
    }
    if (n==1) {
        return 1;
    }
    
    return Fibonacci(n - 1) + Fibonacci(n-2);
}

//迭代   复杂度为n
long Fibonacci2(int n){
    int result[2] = {0,1};
    if (n<2) {
        return result[n];
    }
    
    long fibonacciOne = 0;
    long fibonacciTwo = 1;
    long fibonacciN = 0;
    for (int i = 2; i<=n; ++i) {
        
        fibonacciN = fibonacciOne + fibonacciTwo;
        fibonacciOne = fibonacciTwo;
        fibonacciTwo = fibonacciN;
        
    }
    return  fibonacciN;
}


int main(int argc, const char * argv[]) {
    
    long i = Fibonacci(6);
    long j = Fibonacci2(5);
    
    std::cout<< i <<std::endl;
    std::cout<< j <<std::endl;
    return  0;
    
}
