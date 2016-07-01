//
//  BubbleSort.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/6/3.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
using std::cout;

void bubbleSort(int array[], int count){
    bool sorted = false;
    
    while (!sorted) {
        sorted = true;
        
        for (int i = 0; i < count; i++) {
            if (array[i] > array[i+1]) {
                swap(array[i], array[i+1]);
                sorted = false;
            }
        }
        count--;
    }
}