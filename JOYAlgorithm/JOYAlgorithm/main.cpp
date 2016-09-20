//
//  main.cpp
//  JOYAlgorithm
//
//  Created by Joy on 16/9/20.
//  Copyright © 2016年 Joy. All rights reserved.
//

#include <stdlib.h>
#include <iostream>

using namespace std;
using std::cout;


struct ListNode {
    int value;
    ListNode *next;
};


ListNode *reverseBetween(ListNode *list, int m, int n) {
    
    ListNode *cur;// 存放当前位置
    ListNode *pre = nullptr;// 存放反转前的位置
    ListNode *next;// 下个位置
    ListNode *reversehead;
    ListNode * temp = nullptr;
    
    int index = 1;
    while (cur != NULL) {
        next = cur->next;
        if (index < m) {
            pre = cur;
            cur = next;
        }
        if (index == m) {
            reversehead = cur;
            temp = cur;
            cur = next;
            
        }
        if (index > m && index < n) {
            
            cur->next = temp;
            temp = cur;
            cur = next;
        }
        if (index == n) {
            cur->next = temp;
            pre->next = cur;
        }
        
    }
    return list;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
