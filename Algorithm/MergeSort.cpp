//
//  MergeSort.cpp
//  Algorithm
//
//  Created by wjl on 15/12/3.
//  Copyright © 2015年 Martin. All rights reserved.
//

#include <iostream>

void merge(int a[],int b[],int left,int middle,int right){
    
    int i = left;
    int j = middle +1;
    int k = left;
    while (i<=middle && j<=right) {
        
        if (a[i]<=a[j]) {
            b[k++] = a[i++];
        }
        else{
            b[k++] = a[j++];
        }
        
    }
    if (i<=middle) {
        while (i<=middle) {
            b[k++] = a[i++];
        }
    }
    else{
        while (j<=right) {
            b[k++] = a[j++];
        }
    }
    //将排好序的部分再次放进a数组中
    for (int n = left; n<= right; n++) {
        a[n] = b[n];
    }
    
}


void mergeSort(int a[],int b[],int left,int right){
    
    if (left<right) {
        
        int middle = (left + right)/2 ;
        //递归调用算法本身对从left到mid的数组元素排序
        mergeSort(a, b, left, middle);
        //递归调用算法本身对从mid+1到right的数组元素排序
        mergeSort(a, b, middle+1, right);
        // 合并两段排好序的数组
        merge(a, b, left, middle, right);
        
    }
}

//int main(int argc, const char * argv[]){
//    
//    int a[8]={54,12,43,76,8,9,87,1};
//    int b[8];
//    
//    mergeSort(a,b,0,7);
//    //打印结果
//    for(int q=0;q<8;q++)
//        std::cout<<""<<a[q]<<std::endl;
//    
//    return 0;
//    
//}
