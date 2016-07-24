//
//  array_missingNumber.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/5/27.
//  Copyright © 2016年 Martin. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
using std::cout;

int missingNumber(vector<int>& nums) {
    
    if (nums.size() < 1) {
        return -1;
    }
    
    int result = 0;
    for (size_t i = 0; i < nums.size(); i++) {
        result ^= nums[i] ^ i;
    }
    result ^= nums.size();
    return result;
}




