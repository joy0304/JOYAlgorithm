//
//  BinarySearch.cpp
//  Algorithm
//
//  Created by wjl on 15/11/30.
//  Copyright © 2015年 Martin. All rights reserved.
//

#include <iostream>
int binarySearch(int a[],const int &x ,int n);

//int main(int argc, const char * argv[]) {
//    
//    int temp[5] = {2,5,6,16,43};
//    int result = binarySearch(temp, 43, 5);
//    
//    std::cout<< result << std::endl;
//    return 0;
//}


int binarySearch(int a[],const int &x ,int n){
    
    int left=0 , right = n-1;
    
    while (left<=right) {
        
        int middle = (left + right)/2;
        
        if (x == a[middle]) {
            //返回在数组中的位置
            return  middle;
        }
        else if (x > a[middle]){
            left = middle +1;
        }
        else{
            right = middle -1;
        }
        
    }
    return -1;//代表查找失败
}