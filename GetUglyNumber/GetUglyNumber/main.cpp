//
//  main.cpp
//  GetUglyNumber
//
//  Created by wjl on 16/2/13.
//  Copyright © 2016年 Martin. All rights reserved.
//


#include <stdio.h>
#include <iostream>
using namespace std;

int Min(int number1, int number2, int number3){
    
    int min = (number1 < number2) ? number1 : number2;
    min = (min < number3) ? min : number3;
    
    return min;
}

int GetUglyNumber(int index){
    
    if (index <= 0) {
        return 0;
    }
    
    int* uglyArr = new int[index];
    uglyArr[0] = 1;
    int nextUglyIndex = 1;
    
    int* pMultiply2 = uglyArr;
    int* pMultiply3 = uglyArr;
    int* pMultiply5 = uglyArr;
    
    while (nextUglyIndex < index) {
        
        int min = Min(*pMultiply2 * 2,*pMultiply3 * 3,*pMultiply5 * 5);
        uglyArr[nextUglyIndex] = min;
        
        while (*pMultiply2 * 2 <= uglyArr[nextUglyIndex]) {
            pMultiply2++;
        }
        while (*pMultiply3 * 3 <= uglyArr[nextUglyIndex]) {
            pMultiply3++;
        }
        while (*pMultiply5 * 5 <= uglyArr[nextUglyIndex]) {
            pMultiply5++;
        }
        
        nextUglyIndex++;
        
    }
    
    int ugly = uglyArr[nextUglyIndex-1];
    delete [] uglyArr;
    return ugly;
}

int main(int argc, const char * argv[]) {
    
    int ugly = GetUglyNumber(4);
    printf("%d",ugly);
    return  0;
}
