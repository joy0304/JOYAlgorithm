//
//  main.cpp
//  StringPermutation
//
//  Created by wjl on 16/3/19.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <iostream>


bool IsSwap(char* pBegin,char* pEnd){
    
    char *p;
    for(p = pBegin ; p < pEnd ; p++)
    {
        if(*p == *pEnd)
            return false;
    }
    return true;
}

void Permutation(char* pStr, char* pBegin){
    
    if (pStr == NULL) {
        return;
    }
    
    if (*pBegin == '\0') {
        printf("%s\n",pStr);
    }
    else{
        
        for (char* pch = pBegin; *pch != '\0'; ++pch) {
            
            if(IsSwap(pBegin, pch)){
                char temp = *pch;
                *pch = *pBegin;
                *pBegin = temp;
                
                Permutation(pStr, pBegin++);
                
                temp = *pch;
                *pch = *pBegin;
                *pBegin = *pch;
            }

        }
    }
}

