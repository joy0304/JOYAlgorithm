//
//  hasCycle.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/6/7.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
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

bool hasCycle(ListNode *head) {
    
    if (head == NULL) {
        return false;
    }
    
    ListNode *slow = head->next;
    ListNode *fast = slow->next;
    
    while (fast != NULL && slow != NULL) {
        if (fast == slow) {
            return true;
        }
        slow = slow->next;
        fast = fast->next;
        
        if (fast != NULL) {
            fast = fast->next;
        }
    }
    
    return false;
}
