//
//  InsertSort.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/7/8.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
using std::cout;

void insertSort(int arr[], int n){
    int temp;
    for (int i = 1; i < n; i ++) {
        temp = arr[i];
        int j = i - 1;
        while ((j >= 0 )&&(arr[j] > temp)) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    
    
}

    