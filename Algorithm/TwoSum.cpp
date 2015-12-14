//
//  main.cpp
//  Algorithm
//
//  Created by wjl on 15/11/29.
//  Copyright © 2015年 Martin. All rights reserved.
//
//

#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
std::vector<int> twoSum(int a[], int target,int n);
//int main(int argc, const char * argv[]){
//    
//    int a[] = {2,5,4,87,12};
//    std::vector<int> b = twoSum(a, 16, 5);
//    
//    for (int i =0; i<b.size(); i++) {
//        
//        std::cout<<(b[i]);
//    }
//    return 0;
//    
//}

std::vector<int> twoSum(int a[], int target,int n){
    
    std::map<int,int> Hash;
    std::vector<int> result(2);
    for (int i=0; i<n; i++) {
        
        Hash[a[i]] = i;
    }
    
    for (int j=0; j<n; j++) {
        if (Hash.find(target-a[j]) != Hash.end() && Hash[target-a[j]] != j ) {
            
            result[0]=j+1;
            result[1]=Hash[target - a[j]] + 1;
            break;
        }
    }
    
    return result;
    
}