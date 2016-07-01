//
//  intersect.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/6/28.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
using std::cout;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    
    if (nums1.empty() || nums2.empty()) {
        return result;
    }
    
    unordered_map<int, int>dict;
    for (int i = 0; i < nums1.size(); i++) {
        dict[nums1[i]]++;
    }
    for (int j = 0; j < nums2.size(); j++) {
        if (--dict[nums2[j]] >= 0) {
            result.push_back(nums2[j]);
        }
    }
    return result;
}


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    
    if (nums2.empty() || nums1.empty()) {
        return result;
    }
    
    set<int> s(nums1.begin(), nums1.end());
    for (int x: nums2) {
        if (s.erase(x)) {
            result.push_back(x);
        }
    }
    return result;
}
