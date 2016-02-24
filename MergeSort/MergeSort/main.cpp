//
//  main.cpp
//  MergeSort
//
//  Created by wjl on 16/2/24.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

void merge(int a[], int b[], int left,int middle, int right){
    
    int i = left;
    int j = middle + 1;
    int k = left;
    while (i<=middle && j <=right) {
        if (a[i]<a[j]) {
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
    if (j<=right) {
        while (j<=right) {
            b[k++] = a[j++];
        }
        
    }
    for (int n = left; n<= right; n++) {
        a[n] = b[n];
    }
    
}

void mergeSort(int a[],int b[],int left, int right){
    
    if (left>=right) return;
    
    int middle = (left+right)/2;
    mergeSort(a, b, left, middle);
    mergeSort(a, b, middle+1, right);
    
    merge(a,b,left,middle,right);
    
}


int main(){
    
    int a[8]={54,12,43,76,8,9,87,1};
    int b[8];
    
    mergeSort(a,b,0,7);
    
    for(int q=0;q<8;q++)
        std::cout<<a[q]<<std::endl;
    
    return 0;
}
