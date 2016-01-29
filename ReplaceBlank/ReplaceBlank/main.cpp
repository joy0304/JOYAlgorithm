//
//  main.cpp
//  ReplaceBlank
//
//  Created by wjl on 16/1/29.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
//length是字符数组的总容量
void ReplaceBlank(char string[], int length){
    
    if (string == NULL && length < 0) {
        return;
    }
    
    int originalLength = 0;
    int blankNumber = 0;
    int i = 0;
    while (string[i] != '\0') {
        originalLength ++;
        if (string[i] == ' ') {
            blankNumber ++;
        }
        i ++;
    }
    
    int newLength = originalLength + blankNumber * 2;
    if (newLength > length){
        return;
    }
    
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    //printf("%d,%d",indexOfNew,indexOfOriginal);
    
    while (indexOfNew > indexOfOriginal && indexOfOriginal >= 0) {
        
        if (string[indexOfOriginal] == ' ') {
            string[indexOfNew--] = '0';
            string[indexOfNew--] = '2';
            string[indexOfNew--] = '%';
        }
        
        else{
            string[indexOfNew--] = string[indexOfOriginal];
            
        }
        indexOfOriginal --;
    }
    
    
    std::cout<< string <<std::endl;
    
}


int main(int argc, const char * argv[]) {
    
    
    char string[40] = "we  are happy.";
    
    ReplaceBlank(string, 40);
    
    std::cout<< "" <<std::endl;
    
    return  0;
    
}
