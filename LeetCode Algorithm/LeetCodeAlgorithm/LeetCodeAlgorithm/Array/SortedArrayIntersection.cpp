//
//  SortedArrayIntersection.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/8/15.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
using std::cout;

int* intersection(int aArray[], int aLength, int bArray[], int bLength, int result[]) {
    
    int i = 0, j = 0, k = 0;
    while(i < aLength && j < bLength) {
        if(aArray[i] < bArray[j])
            i++;
        if(aArray[i] > bArray[j])
            j++;
        if(aArray[i] == bArray[j]) {
            result[k++] = aArray[i];
            i++;
            j++;
        }
    }
    return result;
}