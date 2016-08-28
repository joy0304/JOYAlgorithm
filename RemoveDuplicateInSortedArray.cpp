//
//  RemoveDuplicateInSortedArray.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/8/28.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

int removeDuplicateInSortedArray(vector<int> sortedArray) {
    
    if (sortedArray.empty()) {
        return 0;
    }
    int index = 0;
    for (int i = 1; i < sortedArray.size(); i ++) {
        if (sortedArray[i] != sortedArray[index]) {
            sortedArray[++index] = sortedArray[i];
        }
    }
    return index + 1;
}

// 在STL中unique函数是一个去重函数， unique的功能是去除相邻的重复元素(只保留一个),其实它并不真正把重复的元素删除，是把重复的元素移到后面去了，然后依然保存到了原数组中，然后 返回去重后最后一个元素的地址。

// distance 返回间距
long removeDuplicateInSortedArray2(vector<int> sortedArray) {
    
    return distance(sortedArray.begin(), unique(sortedArray.begin(), sortedArray.end()));
    
    // sortedArray.erase(unique(sortedArray.begin(), sortedArray.end()), sortedArray.end());
}




