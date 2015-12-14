//
//  QuickSort.cpp
//  Algorithm
//
//  Created by wjl on 15/12/4.
//  Copyright © 2015年 Martin. All rights reserved.
//

#include <stdio.h>
#include <iostream>

void quickSort(int a[],int start,int end);
int partition(int a[],int start,int end);
void swap(int a, int b);

//int main(int argc, const char * argv[]){
//    
//    int a[8] = {8,4,2,10,1,6,7,9};
//    
//    quickSort(a, 0, 7);
//    
//    for (int i = 0; i<8; i++) {
//        
//        std::cout<< a[i] << std::endl;
//        
//    }
//    
//    return 0;
//    
//}

void quickSort(int a[],int start,int end){
    
    if (start<end) {
        //中心点位置 pivot position
        int pivotPos = partition(a, start, end);
        //对中心点pivotPos的前面的元素排序
        quickSort(a, start, pivotPos-1);
        //对后面的元素排序
        quickSort(a, pivotPos+1, end);
        
    }
}


int partition(int a[],int start,int end){
    
    int i = start;
    int j = end+1;
    //中轴元素
    int x = a[start];
    
    while (true) {
        //如果左侧小于则移动扫描指针
        while (a[++i]<x);
        //右侧大于移动扫描指针
        while (a[--j]>x);
        
        if (i>=j)
            break;
        else{
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    
    a[start] = a[j];
    a[j] = x;
    return j;
}

