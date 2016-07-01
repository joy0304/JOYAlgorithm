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

struct ListNode{
    int value;
    ListNode *next;
};

int main(){
    
    int array[] = {2,4,5,2,6,7,2};
    int arrLength = sizeof(array)/sizeof(int);
    int delNumber = 2;
    int j = 0;
    for (int i = 0; i < arrLength; i++) {
        if (array[i] != delNumber) {
            array[j] = array[i];
            j++;
        }
        
    }
    
    for (int k = 0; k < j; k++) {
        printf("%d \n",array[k]);
    }
    return 0;
}
