//
//  ArrayInsert.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/6/5.
//  Copyright © 2016年 Martin. All rights reserved.
//


#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
using std::cout;

void insert(int *arr, int value, int index){

    int size = (sizeof(arr)/sizeof(arr[0]));


    if (index >= size || size == 0) {
        return;
    }

    for (int i = size; i >= index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index-1] = value;

    for (int i = 0; i <= size; i ++) {
        cout<<arr[i]<<endl;
    }
}
