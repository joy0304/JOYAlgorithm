//
//  main.cpp
//  RecordOddEven
//
//  Created by wjl on 16/2/6.
//  Copyright © 2016年 Martin. All rights reserved.
//


#include <stdio.h>
#include <iostream>
#include <exception>
#include <stdlib.h>

using namespace std;

void Recoder(int* pData,int length){
    
    if (pData == NULL && length <= 0) {
        return;
    }
    
    int* pStart = pData;
    int* pEnd = pData + length -1;
    
    while (pStart<pEnd) {
        while (pStart<pEnd & (*pStart & 1) != 0) {
            
            pStart++;
        }
        while (pStart<pEnd & (*pEnd & 1) == 0) {
            pEnd--;
        }
        
        if (pStart < pEnd) {
            
            int temp = *pStart;
            *pStart = *pEnd;
            *pEnd = temp;
            
        }
    }
    
    for(int i = 0; i < length; ++i)
        printf("%d\t", pData[i]);
    
}


int main(int argc, const char * argv[]) {

    
    int a[] = {1,2,3,4,5,6,7};
    
    Recoder(a, sizeof(a)/sizeof(int));

    return  0;
    
}
