//
//  main.cpp
//  BubbleSort
//
//  Created by wjl on 16/2/24.
//  Copyright © 2016年 Martin. All rights reserved.
//


#include <stdio.h>
#include <iostream>
using namespace std;

void BubbleSort(int a[],int n){
    
    int i, j, temp;
    for (i=0; i<n-1; i++) {
        for (j=0; j < n - i - 1; j++) {
            
            if (a[j]>a[j+1]) {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
    
    
}
void BubbleSort2(int a[], int n){
    
    int i, j, temp;
    bool flag = true;
    for (i = 0; i < n - 1 && flag; i++) {
        flag = false;
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j+1]) {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
                flag = true;
            }
        }
    }
    
}
int main(){
    
    int number[] = {2,5,6,7,21,8,41};
    
    BubbleSort2(number,sizeof(number)/sizeof(number[0]));
    
    for (int i=0; i<7; i++) {
        printf("%d\n",number[i]);
    }
    return 0;
}
