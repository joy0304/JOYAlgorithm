//
//  BubbleTest.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/7/8.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
void BubbleSort(int arrar[], int size) {
    
    bool flag = true;
    
    while (flag) {
        flag = false;
        for (int i = 0 ; i < size; i++) {
            if (arrar[i] > arrar[i+1]) {
                //swap()
                flag = true;
            }
        }
        size--;
    }
}

// 二分查找
int binarySearch(int array[], int target, int size) {
    int left = 0, right = size - 1;
    
    int index = (left + right) / 2;
    
    while (array[index] != target) {
        
        int midlle = array[index];
        if (midlle == target) {
            return midlle;
        }
        else if (midlle < target) {
            left = index + 1;
        }
        else {
            right = midlle - 1;
        }
        
    }
    
    return -1;
}