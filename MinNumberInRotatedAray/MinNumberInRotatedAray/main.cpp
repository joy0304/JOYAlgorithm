//
//  main.cpp
//  MinNumberInRotatedAray
//
//  Created by wjl on 16/2/2.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <exception>

using namespace std;

int MinInOrder(int* numbers, int index1, int index2){
    
    int result = numbers[index1];
    
    for (int i = index1 + 1; i <= index2; ++i) {
        if (result > numbers[i]) {
            result = numbers[i];
        }
    }
    return result;
}

int Min(int* numbers, int length){
    
    if (numbers == NULL || length <= 0) {
        throw new std::exception();
    }
    
    int index1 = 0;
    int index2 = length - 1;
    int indexMid = index1;
    
    while (numbers[index1] >= numbers[index2]) {
        if (index2 - index1 == 1) {
            indexMid = index2;
            break;
        }
        
        indexMid = (index1 + index2) / 2;
        if (numbers[index1] == numbers[indexMid] && numbers[indexMid] == numbers[index2] ) {
            
            return MinInOrder(numbers,index1,index2);
        }
        if (numbers[index1] <= numbers[indexMid]){
            index1 = indexMid;
        }
        else if(numbers[indexMid] <= numbers[index2]){
            index2 = indexMid;
            
        }
    }
    return indexMid;
}



int main(int argc, const char * argv[]) {
    
    try
    {
        Min(NULL, 0);
    }
    catch (...){
        printf("Test failed.\n");
    }
    
    int array2[] = {1, 0, 1, 1, 1};
    int result2 = Min(array2, 5);
    
    std::cout<< result2 <<std::endl;
    
    return  0;
    
}
