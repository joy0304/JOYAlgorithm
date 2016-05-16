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
using namespace std;
using std::cout;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
    int k = m + n - 1;
    int i = m - 1;
    int j = n - 1;
    while (i >=0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i];
            i--;
        }
        else{
            nums1[k--] = nums2[j];
            j--;
        }
    }
    
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}
int main(){
 
        vector<int> Test;
        Test.push_back(1);
        Test.push_back(7);
        Test.push_back(3);
        Test.push_back(2);
        Test.push_back(3);
        Test.push_back(4);
        Test.push_back(3);
        Test.push_back(7);
        Test.push_back(7);
    
    cout << result << endl;
    
}
