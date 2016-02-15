//
//  main.cpp
//  FirstNotRepeatingChar
//
//  Created by wjl on 16/2/15.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

char FirstNotRepeatingChar(char* pString){
    
    if (pString==NULL) {
        return '\0';
    }
    
    int tableSize = 256;
    int hashTable[tableSize];
    for (int i=0; i<tableSize; i++) {
        hashTable[i] = 0;
    }
    
    char* pStrIndex = pString;
    while (*pStrIndex != '\0') {
        hashTable[*pStrIndex]++;
        pStrIndex++;
    }
    
    pStrIndex = pString;
    while (*pStrIndex != '\0') {
        if (hashTable[*pStrIndex] == 1) {
            return *pStrIndex;
        }
        pStrIndex++;
    }
    
    return '\0';
}


int main(int argc, const char * argv[]) {
    
    char result = FirstNotRepeatingChar("asdfgkjhsad");
    
    printf("%c\n",result);
    
    return  0;
    
}




