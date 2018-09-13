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
    obj->val  = -1;
    obj->next = NULL;
    return obj;
}

MyLinkedList* getNode(MyLinkedList* obj, int index){
    MyLinkedList* cur = obj;
    for(int i = 0; i < index && cur; i++){
        cur = cur->next;
    }
    return cur;
}

MyLinkedList* getTail(MyLinkedList* obj){
    MyLinkedList* cur = obj;
    while(cur && cur->next){
        cur = cur->next;
    }
    return cur;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList* cur = getNode(obj, index);
    return (cur == NULL || cur->val == -1) ? -1 : cur->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    int tmpval;
    MyLinkedList* cur = myLinkedListCreate();
    cur->val = val;
    if (obj->val != -1){
        tmpval = obj->val;
        obj->val = cur->val;
        cur->val = tmpval;
        cur->next = obj->next;
        obj->next = cur;
    }else {
        obj->val = val;
    }
    return;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if (obj == NULL){
        myLinkedListAddAtHead(obj, val);
        return;
    }
    MyLinkedList* prev = getTail(obj);
    MyLinkedList* cur  = myLinkedListCreate();
    cur->val = val;
    prev->next = cur;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList* node    = obj;
    MyLinkedList* newNode = myLinkedListCreate();
    newNode->val = val;
    if (index == 0){
        myLinkedListAddAtHead(obj, val);
        return;
    }
    MyLinkedList* prev = getNode(obj, index-1);
    if (prev == NULL || prev-> val == -1) {
        return;
    }
    MyLinkedList* cur = myLinkedListCreate();
    cur->val = val;
    MyLinkedList* next = prev->next;
    cur->next = next;
    prev->next = cur;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList* cur = getNode(obj, index);
    if (cur == NULL){
        return;
    }
    MyLinkedList* prev = getNode(obj, index-1);
    MyLinkedList* next = cur->next;
    if (prev) {
        prev->next = next;
    } else{
        obj = next;
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
    myLinkedListAddAtHead(obj, 7);
    myLinkedListAddAtTail(obj, 7);
    myLinkedListAddAtHead(obj, 9);
    myLinkedListAddAtTail(obj, 8);
    myLinkedListAddAtHead(obj, 6);
    param_1 = myLinkedListGet(obj, 3);
    printf("%d\n", param_1);
    myLinkedListShow(obj);
    myLinkedListFree(obj);
    getchar();
    return 0;
}
