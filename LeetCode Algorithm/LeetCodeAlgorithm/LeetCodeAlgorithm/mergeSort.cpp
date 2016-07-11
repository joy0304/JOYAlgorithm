//
//  mergeSort.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/7/11.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>


void merge(int a[], int b[], int left, int middle, int right) {
 
    int i = left;
    int j = middle + 1;
    int k = left;
    if (i <= middle && j <= right) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        }
        else {
            b[k++] = a[j++];
        }
    }
    if (i <= middle) {
        while (i <= middle) {
            b[k++] = a[i++];
        }
    }
    else {
        while (j <= right) {
            b[k++] = a[j++];
        }
    }
}

void mergeSort(int a[], int b[], int left, int right){
    
    if (a == NULL) {
        return;
    }
    if (left < right) {
        int middle = left + right;
        mergeSort(a, b, left, middle);
        mergeSort(a, b, middle+1, right);
        merge(a, b, left, middle, right);
    }
}