//
//  twoSum.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/9/13.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;


vector<int> twoSum(int target, vector<int> nums) {
    
    vector<int> result;
    unordered_map<int, int> map;
    
    for (int i = 0; i < nums.size(); i ++) {
        map[nums[i]] = i;
    }
    
    for (int i = 0; i < nums.size(); i ++) {
        int value = target - nums[i];
        
        if (map.find(value) != map.end() && map[value] > i) {
            
            result.push_back(i + 1);
            result.push_back(map[value]+1);
            break;
        }
    }
    return result;
    
}