//
//  array_mergeTwoLists.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/5/30.
//  Copyright © 2016年 Martin. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
using std::cout;
struct ListNode {
    
    int value;
    ListNode *next;
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    
    ListNode *mergeList = NULL;
    
    if (l1->value < l2->value) {
        mergeList = l1;
        mergeList->next = mergeTwoLists(l1->next, l2);
    }
    else {
        mergeList = l2;
        mergeList->next = mergeTwoLists(l1, l2->next);
    }
    
    return mergeList;
}

ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
    
    ListNode *mergeList = NULL;
    
    if (l1 && l2) {
        if (l1->value < l2->value) {
            mergeList->next = l1;
            l1 = l1->next;
        }
        else {
            mergeList->next = l2;
            l2 = l2->next;
        }
        
        mergeList = mergeList->next;
    }
    
    mergeList->next = l1 ? l1 : l2;
    
    return mergeList;
    
}
