//
//  deleteRepeatNode.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/8/15.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
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

//void removeRep(ListNode *list){
//    
//    hash *imap;
//    
//    ListNode *pre = list;
//    ListNode *cur = list->next;
//    while (cur != NULL) {
//        if (imap.find(cur->value)) {
//            pre->next = cur->next;
//        }
//        else {
//            imap.insert(cur-value);
//            pre = cur;
//        }
//        cur = cur->next;
//    }
//}