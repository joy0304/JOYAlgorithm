//
//  main.cpp
//  MaxAndMin
//
//  Created by wjl on 16/2/23.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <iostream>
using namespace std;
void MaxAndMix(int* array, int left, int right, int& maxValue, int& minValue){
    
    if (array==NULL) {
        maxValue=minValue=NULL;
        return;
    }
    
    if (left==right) {
        minValue=maxValue=array[left];
        return;
    }
    
    if (left == right-1) {
        if(array[left]>array[right])
        {
            maxValue = array[left];
            minValue = array[right];

        }
        else
        {
            maxValue = array[right];
            minValue = array[left];
        }
        return;

    }
    
    int middle = (left+right)/2;
    int leftMax, leftMin;
    MaxAndMix(array, left, middle, leftMax, leftMin);
    
    int rightMax, rightMin;
    MaxAndMix(array, middle, right, rightMax, rightMin);
    
    maxValue = max(leftMax, rightMax);
    minValue = min(leftMin, rightMin);
    
    
}

int main()
{
    int a[10]={0,9,1,6,3,4,8,2,7,5};
    int maxValue, minValue;
    MaxAndMix(a, 0, 9, maxValue, minValue);
    cout<<maxValue<<","<<minValue<<endl;
    return 0;
}