//
//  FindInPartiallySortedMatrix.cpp
//  TestAlgorithm
//
//  Created by wjl on 16/1/24.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
//以右上角开始寻找
bool findTopRight(int* martix,int rows, int columns, int number){
    
    bool found = false;
    
    if (martix != NULL && rows > 0 && columns > 0) {
        
        int row = 0;
        int column = columns - 1;
        while (row < rows && column >= 0) {
            
            if (martix[row * columns + column] == number) {
                found = true;
                break;
            }
            else if(martix[row * columns + column] > number){
                --column;
            }
            else{
                ++row;
            }
        }
        
    }
    return found;
}
//从左下角开始找
bool findBottomLeft(int* martix,int rows, int columns, int number){
    
    bool found = false;
    
    if (martix != NULL && rows > 0 && columns > 0) {
        
        int column = 0;
        int row = rows - 1;
        while (row >= 0 && column < columns) {
            if (martix[row * columns + column] == number) {
                found = true;
                break;
            }
            else if (martix[row * columns + column] > number){
                --row;
            }
            else{
                ++column;
            }
        }
        
    }
    return found;
}


int main(int argc, const char * argv[]) {
    
    
    int matrix[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    bool resultTopRight = findTopRight((int*)matrix, 4, 4, 7);
    std::cout<< resultTopRight <<std::endl;
    
    bool resultBottomLeft = findBottomLeft((int*)matrix, 4, 4, 19);
    std::cout<< resultBottomLeft <<std::endl;
    
    return 0;
}
