//
//  deleteNode.cpp
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

void deleteNode(ListNode *List, ListNode *delNode){
    
    if (!List || !delNode) {
        return;
    }
    
    if (delNode->next != NULL) {
        
        ListNode *node = delNode->next;
        delNode->value = delNode->next->value;
        delNode->next = node->next;
        
        delete node;
        node = NULL;
    }
    else if (List == delNode) {
        delete delNode;
        delNode = NULL;
        List = NULL;
        
    }
    else {
        
        ListNode *node = List;
        while (node->next != delNode) {
            node = node->next;
        }
        
        node->next = NULL;
        delete delNode;
        delNode = NULL;
        
    }
    
}