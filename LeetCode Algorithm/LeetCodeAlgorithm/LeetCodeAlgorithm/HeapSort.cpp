//
//  HeapSort.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/7/13.
//  Copyright © 2016年 Martin. All rights reserved.
//

// 调整为最大堆
#include <stdio.h>

void heapAdjust(int arr[], int start, int end) {
    
    int temp, j;
    temp = arr[start];
    for (j = start * 2; start < end; j *= 2) {
        if (j < end && arr[j < arr[j+1]]) {
            ++j;
        }
        if (temp > arr[j]) {
            break;
        }
        else {
            arr[start] = arr[j];
            start = j;
        }
    }
    arr[start] = temp;
    
}

void heapSort(int arr[], int size) {
    int i;
    for (i = arr[size/2]; i>0; i--) {
        heapAdjust(arr, i, size);
    }
    for (i = arr[size]; i > 1; i --) {
        //swap();
        heapAdjust(arr, i, size);
    }
}

