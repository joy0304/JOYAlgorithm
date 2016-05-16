//
//  Array_removeElement.cpp
//  LeetCodeAlgorithm
//
//  Created by wjl on 16/5/16.
//  Copyright © 2016年 Martin. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
using std::cout;

int removeElement(vector<int>& nums, int val) {
    int index = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[index++] = nums[i];
        }
    }
    return index;
}