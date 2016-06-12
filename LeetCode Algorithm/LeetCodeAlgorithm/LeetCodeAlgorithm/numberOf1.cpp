//
//  numberOf1.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/6/7.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
using std::cout;

int numberOf1(int n){
    
    int count = 0;
    
    int flag = 1;
    while (flag) {
        if (flag & n) {
            count++;
        }
        
        flag = flag << 1;
    }
    return count;
}