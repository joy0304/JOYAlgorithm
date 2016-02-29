//
//  TestTwo.cpp
//  TestAlgorithm
//
//  Created by wjl on 16/2/28.
//  Copyright © 2016年 Martin. All rights reserved.
//
#include <iostream>
#include <stdio.h>

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

char* ReverseSentence(char* pData){
    
    if(pData == NULL){
        return NULL;
    }
    
    char* pStart = pData;
    char* pEnd = pData;
    while (*pEnd != '\0') {
        pEnd++;
    }
    pEnd--;
    
    Reverse(pStart, pEnd);
    
    // 翻转每个单词
    pStart = pEnd = pData;
    
    while (*pStart!='\0') {
        if (*pStart == ' ') {
            pStart++;
            pEnd++;
        }
        else if (*pEnd == ' ' || *pEnd == '\0') {
            Reverse(pStart, --pEnd);
            pStart = ++pEnd;
        }
        else{
            pEnd++;
        }
    }
    return pData;
}

int main(){
    
    char Test[] = "I am Boy";
    
    ReverseSentence(Test);
    
    cout<< Test << endl;
    
    return 0;
}