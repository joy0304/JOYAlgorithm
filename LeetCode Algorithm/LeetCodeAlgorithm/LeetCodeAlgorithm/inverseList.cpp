//
//  inverseList.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/7/8.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
struct ListNode{
    int value;
    ListNode *next;
    
};

void inverseList(ListNode *head) {
    
    ListNode *newList = new ListNode();
    
    if (head == NULL) {
        return;
    }
    
    while (head != NULL) {
        
        ListNode *tempNode = head->next;
        head->next = newList;
        head = tempNode;
    }
    
}