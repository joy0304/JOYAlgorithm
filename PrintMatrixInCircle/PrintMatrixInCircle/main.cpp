//
//  main.cpp
//  PrintMatrixInCircle
//
//  Created by wjl on 16/2/7.
//  Copyright © 2016年 Martin. All rights reserved.
//


#include <stdio.h>
#include <iostream>
#include <exception>
#include <stdlib.h>

using namespace std;

void PrintMatrixInCircle(int** numbers, int columns, int rows, int start)
{
    int endX = columns - 1 - start;
    int endY = rows - 1 - start;
    
    for(int i = start; i <= endX; ++i)
    {
        int number = numbers[start][i];
        printf("%d \n",number);
    }
    
    if(start < endY)
    {
        for(int i = start + 1; i <= endY; ++i)
        {
            int number = numbers[i][endX];
            printf("%d \n",number);
        }
    }
    
    if(start < endX && start < endY)
    {
        for(int i = endX - 1; i >= start; --i)
        {
            int number = numbers[endY][i];
            printf("%d \n",number);
        }
    }
    
    if(start < endX && start < endY - 1)
    {
        for(int i = endY - 1; i >= start + 1; --i)
        {
            int number = numbers[i][start];
            printf("%d \n",number);
        }
    }
}

void PrintMatrixClockWisely(int** numbers, int columns, int rows)
{
    if(numbers == NULL || columns <= 0 || rows <= 0)
        return;
    
    int start = 0;
    
    while(columns > start * 2 && rows > start * 2)
    {
        PrintMatrixInCircle(numbers, columns, rows, start);
        
        ++start;
    }
}

int main(int argc, const char * argv[]) {
    
    int rows =4 ,columns = 4;
    
    int** numbers = new int*[rows];
    for(int i = 0; i < rows; ++i)
    {
        numbers[i] = new int[columns];
        for(int j = 0; j < columns; ++j)
        {
            numbers[i][j] = i * columns + j + 1;
        }
    }
    
    PrintMatrixClockWisely(numbers, 4, 4);
    
    for (int i = 0; i<rows; i++) {
        delete [] (int*)numbers[i];
    }
    
    delete[] numbers;
    
    return  0;
    
}

