//
//  main.cpp
//  JOYAlgorithm
//
//  Created by Joy on 16/9/20.
//  Copyright © 2016年 Joy. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
#include <string.h>
#include <iostream>
#include <vector>
#include <set>

using namespace std;
using std::cout;
struct ListNode{
    int value;
    ListNode *next;

};


ListNode *addTWoNumber (ListNode *L1, ListNode *L2) {

    int carry = 0;

    ListNode *list = new ListNode();
    for (;
         L1 != NULL;
         L1 = L1->next == NULL ? NULL : L1->next,
         L2 = L2->next == NULL ? NULL : L2->next) {
        
        int a = L1 == NULL ? 0 : L1->value;
        int b = L2 == NULL ? 0 : L2->value;
        
        int value = (a + b + carry) % 10;
        carry = (a +b +carry) / 10;
        list->next = new ListNode();
        list->next->value = value;
    }
    if (carry > 0) {
        list->next = new ListNode();
        list->next->value = carry;
    }
    return list;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
