//
//  LeetCodeAlgorithm
//
//  Created by wjl on 16/5/14.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <string.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result(2);
    map<int, int> hash;
    
    for(int i = 0;i < nums.size();i++){
        hash[nums[i]] = i;
    }
    
    for (int j = 0; j < nums.size(); j++) {
        // end 是末尾，里面没有实际元素
        if ((hash.find(target - nums[j]) != hash.end()) && (hash[target - nums[j]] != j)) {
            result[0] = j;
            result[1] = hash[target - nums[j]];
            break;
        }
    }
    
    
    return result;
}




//int main(){
//    
//    vector<int> Test;
//    for (int i = 0; i < 10; i++) {
//        Test.push_back(i);
//    }
//    vector<int> result = twoSum(Test, 6);
//    
//    for (int i = 0; i < result.size(); i++) {
//        cout<< result[i] <<endl;
//    }
//    
//    return 0;
//}
