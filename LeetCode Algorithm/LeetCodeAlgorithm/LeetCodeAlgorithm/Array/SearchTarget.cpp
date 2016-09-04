#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>nums, int target) {
    
    int first = 0;
    int last = nums.size();
    while (first != last) {
        int mid = first + (first - last) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[first] < nums[mid]) {
            if (nums[first < target && target < nums[mid]]) {
                last = mid - 1;
            }
            else {
                first = mid + 1;
            }
        }
        else if(nums[first] > nums[mid]){
            if (target > nums[mid] && target < nums[last]) {
                first = mid + 1;
            }
            else {
                last = mid - 1;
            }
        }
        else {
            // 往后走一步，跳过重复的
            first++;
        }
    }
    return -1;
}

// 在数组中，查找某一个元素,考虑数组中有重复的情况    1、3、1、1、1

//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//(i.e.,  0、1、2、3、4、5、6  might become    4、5、6、7、0、1、2 ).
//You are given a target value to search. If found in the array return its index, otherwise return -1. You may assume no duplicate exists in the array.
