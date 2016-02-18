//
//  main.cpp
//  GetTimesOfNumber
//
//  Created by wjl on 16/2/18.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int GetFirstNumber(int* data,int length,int number,int start,int end){
    
    if (start>end) {
        return -1;
    }
    
    int middleIndex = (start+end)/2;
    int middleData = data[middleIndex];
    
    if (middleData == number) {
        if ((middleIndex>0 && data[middleIndex-1]!=number) || middleIndex==0 ){
            return middleIndex;
        }
        else
            end = middleIndex-1;
    }
    else if (middleData>number){
        end = middleIndex-1;
    }
    else{
        start = middleIndex+1;
    }
    
    return GetFirstNumber(data, length, number, start, end);
    
}


int GetLastNumber(int* data,int length,int number,int start,int end){
    if (start>end) {
        return -1;
    }
    
    int middleIndex = (start+end)/2;
    int middleData = data[middleIndex];
    
    if (middleData==number) {
        if ((middleIndex<length-1 && data[middleIndex+1]!=number) || middleIndex==length-1) {
            return middleIndex;
        }
        else{
            start = middleIndex+1;
        }
    }
    else if (middleData<number){
        start = middleIndex+1;
    }
    else{
        end = middleIndex-1;
    }
    return GetLastNumber(data, length, number, start, end);
}

int main(int argc, const char * argv[]) {
    
    int a[] = {1,2,3,3,3,3,4,5};
    
    int first = GetFirstNumber(a, 8, 3, 0, 7);
    int last = GetLastNumber(a, 8, 3, 0, 7);
    
    if (first>-1 && last>-1) {
        int number = last - first + 1;
        printf("%d\n",number);
    }
    
    return  0;
    
}




