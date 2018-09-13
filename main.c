#include <stdio.h>
#include <stdlib.h>

typedef struct _LinkNode {
    struct _LinkNode* next;
    int val;
} LinkNode;
LinkNode* allocLinkNode(int val) {
    LinkNode* r = (LinkNode*)malloc(sizeof(LinkNode));
    r->val = val;
    r->next = NULL;
    return r;
}
typedef struct {
    LinkNode* head, *tail;
    int count;
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* r = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    r->head = NULL;
    r->tail = NULL;
    r->count = 0;
    return r;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index >= obj->count) return -1;
    LinkNode* p = obj->head;
    while(p != NULL && index>0) {
        p = p->next;
        index--;
    }
    return p->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    LinkNode*n = allocLinkNode(val);
    if (obj->head == NULL) obj->head = obj->tail = n;
    else {
        n->next = obj->head;
        obj->head = n;
    }
    obj->count++;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    LinkNode*n = allocLinkNode(val);
    if (obj->head == NULL) obj->head = obj->tail = n;
    else {
        obj->tail->next = n;
        obj->tail = n;
    }
    obj->count++;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index == 0) return myLinkedListAddAtHead(obj, val);
    if (index == obj->count) return myLinkedListAddAtTail(obj, val);
    if (index > obj->count) return;
    LinkNode* p = obj->head;
    index--;
    while(p != NULL && index>0) {
        p = p->next;
        index--;
    }
    LinkNode*n = allocLinkNode(val);
    n->next = p->next;
    p->next = n;
    obj->count++;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index >= obj->count) return;
    obj->count--;
    LinkNode*p = obj->head;
    if (index == 0) {
        obj->head = p->next;
        free(p);
        if (obj->head == NULL) obj->tail = NULL;
        return;
    }
    index--;
    while(p != NULL && index>0) {
        p = p->next;
        index--;
    }
    if (p->next == obj->tail) obj->tail = p;
    LinkNode*t = p->next;
    p->next = t->next;
    free(t);

}

void myLinkedListFree(MyLinkedList* obj) {
    LinkNode*p = obj->head, *t;
    while(p != NULL) {
        t = p;
        p = p->next;
        free(t);
    }
    free(obj);
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
    myLinkedListFree(obj);
    getchar();
    return 0;
}
