//
//  List.cpp
//  LeetCodeAlgorithm
//
//  Created by Joy on 16/6/12.
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

ListNode* createListNode(int value){
    ListNode *node = new ListNode();
    if (value) {
        node->value = value;
        node->next = NULL;
    }
    
    return node;
}

void linkList(ListNode *node1, ListNode *node2){
    if (node1 && node2) {
        node1->next = node2;
    }
}

void insertNode(ListNode *list, ListNode *node, int value){
    if (list && node) {
        ListNode *newNode = new ListNode();
        newNode->value = value;
        
        newNode->next = node->next;
        node->next = newNode;
    }
    
}

// 在第i个位置上插入
bool insertNode(ListNode *list, int i, int value){
    
    if (list == NULL || i == 0) {
        ListNode *newNode = new ListNode();
        newNode->value = value;
        newNode->next = list;
        list = newNode;
    }
    else{
        ListNode *current = list;
        for (int k = 1; k < i; k++) {
            if (current == NULL) {
                return false;
            }
            else
                current = current->next;
        }
        
        ListNode *newNode = new ListNode();
        newNode->value = value;
        newNode->next = current->next;
        current->next = newNode;
    }
    
    return true;
}


void delNode(ListNode *List, ListNode *delNode){
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

//int main(){
//    ListNode *node1 = createListNode(1);
//    ListNode *node2 = createListNode(2);
//    ListNode *node3 = createListNode(3);
//    
//    linkList(node1, node2);
//    linkList(node2, node3);
//    
//    insertNode(node1, node2, 6);
//    delNode(node1, node2);
//    
//    while (node1->next != NULL) {
//        printf("%d",node1->value);
//        node1 = node1->next;
//    }
//    
//    printf("%d",node1->value);
//}

