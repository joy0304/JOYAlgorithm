//
//  LongestConsecutiveSequence.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/9/13.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;
// 2.1.6
int longSequence(vector<int> nums){
    
    unordered_map<int, bool> map;
    int longest = 0;
    
    
    for (auto i : nums)
        map[i] = false;
    
    for (auto j : nums) {
        if (map[j] == true) {
            continue;
        }
        
        map[j] = true;
        
        for (int k = j+1; map.find(k) != map.end(); k++) {
            map[k] = true;
            ++longest;
        }
        
        for (int k = j-1; map.find(k) != map.end(); --k) {
            map[k] = true;
            ++longest;
        }
    }
    return longest;
}