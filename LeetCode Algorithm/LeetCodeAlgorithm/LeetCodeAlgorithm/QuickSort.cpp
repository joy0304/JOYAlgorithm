//
//  QuickSort.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/7/11.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>

int partition(int arr[], int start, int end) {
    int i = start;
    int j = end;
    int x = arr[i];
    
    while (true) {
        while (arr[i] < x) {
            i++;
        }
        while (arr[j] > x) {
            j++;
        }
        
        if (i >= j) {
            break;
        }
        else {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[start] = arr[j];
    arr[j] = x;
    return j;
}



void quickSort(int arr[],int start,int end){
    
    if (start < end) {
        int pivoit = partition(arr, start, end);
        quickSort(arr, start, pivoit);
        quickSort(arr, pivoit + 1, end);
    }
}