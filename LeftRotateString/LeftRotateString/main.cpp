//
//  main.cpp
//  LeftRotateString
//
//  Created by wjl on 16/2/29.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

void Reverse(char* pStart, char* pEnd){
    
    if (pStart == NULL || pEnd == NULL) {
        return;
    }
    
    while (pStart<pEnd) {
        
        char temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;
        
        pStart++;
        pEnd--;
    }
    
}

char* LeftRotateString(char* pData,int n){
    
    if (pData!=NULL) {
        long nLength = strlen(pData);
        if (nLength>0 && n>0 && n<nLength) {
            char* pFirstStart = pData;
            char* pFirstEnd = pData + n - 1;
            char* pSecondStart = pData + n;
            char* pSecondEnd = pData + nLength;
            
            reverse(pFirstStart, pFirstEnd);
            reverse(pSecondStart, pSecondEnd);
            reverse(pFirstStart, pSecondEnd);
        }
    }
    return pData;
}


int main(){
    
    char test[] = "abcde";
    
    LeftRotateString(test, 2);
    
    cout<< test << endl;
    
    return 0;
}