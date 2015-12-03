//
//  Hanoi.cpp
//  Algorithm
//
//  Created by wjl on 15/11/29.
//  Copyright © 2015年 Martin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
void Hanoi(char a,char b,char c,int n);
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    
//    char a = 'a' ,b = 'b',c = 'c';
//    int n = 3 ;
//    Hanoi(a, b, c, n);
//    return 0;
//}

//有圆盘N个，然后从a移到b，辅助为c
void Hanoi(char a,char b,char c,int n){
    if (n==1){
        printf("%c->%c \n",a,b);
    }
    else{
        Hanoi(a, c, b, n-1);
        printf("%c->%c \n",a,b);
        Hanoi(c,b,a,n-1);
    }
}