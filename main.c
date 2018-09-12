#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int val;
    struct list* next;
}MyLinkedList;
// struct list MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj;
    obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->val  = 0;
    obj->next = NULL;
    return obj;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList* node = obj;
    if (index < 0) {
        return -1;
    }
    else {
        for(int cnt = 0; cnt < index; cnt++) {
            if (node->next == NULL) return -1;
            node = node->next;
        }
        return node->val;
    }
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    int tmpVal;
    MyLinkedList* node = myLinkedListCreate();
    if (obj->val != 0){
        tmpVal    = obj->val;
        obj->val  = val;
        node->val = tmpVal;
        node->next = obj->next;
        obj->next  = node;
    }
    else{
        obj->val = val;
    }
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* tail = obj;
    MyLinkedList* node = myLinkedListCreate();
    node->val = val;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = node;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList* node    = obj;
    MyLinkedList* newNode = myLinkedListCreate();
    newNode->val = val;
    if (index == 0){
        myLinkedListAddAtHead(obj, val);
    }else {
        for(int cnt = 1; cnt < index; cnt++) {
            if (node->next == NULL) return;// The index is greater than the length.
            node = node->next;
        }
        if(node->next == NULL){
            myLinkedListAddAtTail(obj, val);
        }
        else {
            newNode->next = node->next;
            node->next    = newNode;
        }
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList* node = obj;
    if (index == 0){
        obj = NULL;
    }else {
        for(int cnt = 1; cnt < index; cnt++) {
            if (node->next == NULL) return;// The index is greater than the length.
            node = node->next;
        }
        if(node->next == NULL){
            node = NULL;
        }
        else {
            node->next = node->next->next;
        }
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList* head = obj;
    MyLinkedList* freeList;
    while(head != NULL && head->val != 0)
    {
        freeList = head;
        head = head->next;
        free(freeList);
    }
}

void myLinkedListShow(MyLinkedList* obj){
    MyLinkedList* head = obj;
    while(head != NULL)
    {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("NULL\n");
}
/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * struct MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */

int main(void)
{
    int param_1;
    MyLinkedList* obj = myLinkedListCreate();
    myLinkedListAddAtHead(obj, 1);
    myLinkedListShow(obj);
    myLinkedListAddAtTail(obj, 3);
    myLinkedListShow(obj);
    myLinkedListAddAtIndex(obj, 1, 2);
    myLinkedListShow(obj);
    param_1 = myLinkedListGet(obj, 1);
    printf("Get|%d\n", param_1);
    myLinkedListDeleteAtIndex(obj, 1);
    myLinkedListShow(obj);
    param_1 = myLinkedListGet(obj, 1);
    printf("Get|%d\n", param_1);
    myLinkedListFree(obj);
    getchar();
    return 0;
}
