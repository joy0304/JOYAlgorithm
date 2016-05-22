//
//  Test.cpp
//  LeetCodeAlgorithm
//
//  Created by wjl on 16/5/14.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
using std::cout;

bool containsDuplicate(vector<int>& nums) {
    
    return nums.size() > set<int>(nums.begin(), nums.end()).size();
}

int main(){
 
    
}
