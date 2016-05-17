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

int majorityElement (int array[], int n) {
    
    
    if (array == NULL || n <= 0 ){
        return -1;
    }
    
    int temp = array[0];
    int nums = 1;
    for (int i = 1; i < n; i++) {
        
        if (temp == array[i]) {
            nums++;
        }
        else {
            nums--;
            if (nums == 0) {
                temp = array[i];
                nums = 1;
            }
        }
    }
    if (nums > 0) {
        return temp;
    }
    else {
        return -1;
    }

}


int main(){
 
    int temp[9] = {1,2,3,1,1,2,1,1,7};
    int result = majorityElement(temp, 9);
    cout << result << endl;

    
}
