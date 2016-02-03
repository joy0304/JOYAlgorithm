//
//  main.cpp
//  PowerWithExponent
//
//  Created by wjl on 16/2/3.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <exception>

using namespace std;

bool equal(double num1, double num2){
    
    if ((num1 - num2)>-0.000001 && (num1 - num2)<0.0000001) {
        return true;
    }
    else
        return false;
}

double PowerWithExponent(double base, int exponent){
    
    double result = 1.0;
    
    for (int i = 1; i <= exponent; ++i) {
        
        result *= base;
    }
    return result;
}

double Power(double base, int exponent){
    
    if (equal(base,0.0) && exponent < 0) {
        
        throw new std::exception();
        //return 0.0;
    }
    
    int absExponent = (unsigned int)(exponent);
    
    if (exponent < 0) {
        absExponent = (int)(-exponent);
    }
    
    double result = PowerWithExponent(base, exponent);
    
    if (exponent < 0) {
        result = 1.0 / result;
    }
    
    return  result;
}




int main(int argc, const char * argv[]) {
    
    int result;
    
    try
    {
        result = Power(2, 3);
    }
    catch (...){
        printf("Test failed.\n");
    }
    
    std::cout<< result <<std::endl;
    return  0;
    
}
