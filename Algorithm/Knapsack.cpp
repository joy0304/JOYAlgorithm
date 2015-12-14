//
//  Knapsack.cpp
//  Algorithm
//
//  Created by wjl on 15/12/14.
//  Copyright © 2015年 Martin. All rights reserved.
//

#include <iostream>
void knapsack(int n, float M, float v[], float w[], float x[]);

int main(int argc, const char * argv[]){
    
    
    float v[] = {24,15,25};
    float w[] = {15,10,18};
    float M = 20;
    float x[4] = {0,0,0};
    
    knapsack(3, M, v, w, x);
    
    for(int i=1; i<=3; i++)
    {
        std::cout<<"["<<i<<"]:"<<x[i]<<std::endl;
    }
    
    
    return 0;
    
}

void knapsack(int n, float M, float v[], float w[], float x[]){
    
    //单位重量价值排序
    //sort(n,v,w)
    
    int i ;
    //背包剩余容量
    float c = M;
    
    for (i=1; i<=n; i++) {
        
        if (w[i]>c) {
            break;
        }
        x[i] = 1;
        c = c - w[i];
        
    }
    if (i<=n) {
        x[i] = c/w[i];
    }
    
}

