//
//  main.cpp
//  QuickSort
//
//  Created by wjl on 16/2/25.
//  Copyright © 2016年 Martin. All rights reserved.
//


#include <stdio.h>
#include <iostream>
using namespace std;
int Partition(int a[], int start, int end);

void QuickSort(int a[],int start,int end){
    
    if (start<end) {
        int patition = Partition(a, start, end);
        QuickSort(a, start, patition);
        QuickSort(a, patition+1 , end);
    }
    
}

int Partition(int a[], int start, int end){
    
    int i = start;
    int j = end+1;
    int x = a[start];
    
    while (true) {
        
        while (a[++i]<x) {
        }
        while (a[--j]>x) {
        }
        
        if (i>=j) {
            break;
        }
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


int main(){
    
    int a[8]={54,12,43,76,8,9,87,1};
    
    QuickSort(a, 0, 7);
    
    for(int q=0;q<8;q++)
        std::cout<<a[q]<<std::endl;
    
    return 0;
}

