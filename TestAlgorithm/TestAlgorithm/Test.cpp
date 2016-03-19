//
//  main.cpp
//  BinaryTreeInOrder
//
//  Created by wjl on 16/2/19.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include <set>
using namespace std;
void Permutation(char* pStr, char* pBegin);

//void Permutation(char* pStr)
//{
//    if(pStr == NULL)
//        return;
//    
//    Permutation(pStr, pStr);
//}

void Permutation(char* pStr, char* pBegin)
{
    if(*pBegin == '\0')
    {
        printf("%s\n", pStr);
    }
    else
    {
        for(char* pCh = pBegin; *pCh != '\0'; ++ pCh)
        {
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
            
            Permutation(pStr, pBegin + 1);
            
            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
        }
    }
    
}

int main(){
    
    char string2[] = "abc";
    Permutation(string2,string2);
    
    return 0;
    
}