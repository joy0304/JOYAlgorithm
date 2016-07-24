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

ListNode* swapPair(ListNode* head) {
    ListNode *next = head->next;
    head->next = swapPair(next->next);
    next->next = head;
    
    return next;
}


ListNode* swapPairs(ListNode* head) {
    if(head == NULL)
        return NULL;
    if(head->next == NULL)
        return head;
    
    ListNode* next = head->next;
    head->next = swapPairs(next->next);
    next->next = head;
    
    return next;
}
ListNode* CreateListNode(int value){
    
    ListNode* pNode = new ListNode();
    pNode->value = value;
    pNode->next = NULL;
    
    return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext){
    
    if (pCurrent == NULL) {
        printf("error");
        exit(1);
    }
    
    pCurrent->next = pNext;
}