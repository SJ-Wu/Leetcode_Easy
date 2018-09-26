/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* newHead = head;
    struct ListNode* cur = head;
    struct ListNode* prev;

    if (head == NULL) return NULL;

    while (cur && cur->val == val) // case: head->val == val
    {
        cur = cur->next;
        newHead = cur;
    }

    if(newHead == NULL) return NULL;

    prev = cur;
    cur  = cur->next;
    while(cur && cur->next && prev)
    {
        if (cur->val == val)
        {
            prev->next = cur->next;
            cur  = prev->next;
        }
        else
        {
            cur = cur->next;
            prev = prev->next;
        }
        printf("prev.cur|%d.%d\n", prev->val, cur->val);
    }

    if (cur && cur->val == val && cur->next == NULL)
    {
        prev->next = NULL;
    }

    return newHead;
}

void main()
{
    struct ListNode* head = NULL;
    struct ListNode* prev = NULL;
    struct ListNode* cur  = NULL;
    int num;
    printf("length of linkedlist|");
    scanf("%d", &num);

    if (num > 0)
    {
        head = malloc(sizeof(struct ListNode));
        printf("Enter value|");
        scanf("%d", &head->val);
        head->next = NULL;
        cur  = head->next;
        prev = head;
    }

    for(int i = 1; i < num; i++)
    {
        cur = malloc(sizeof(struct ListNode));
        cur->val  = 0;
        cur->next = NULL;
        printf("Enter value|");
        scanf("%d", &cur->val);
        prev->next = cur;
        prev = cur;
        cur  = cur->next;
    }

    head = removeElements(head, 2);
    while(head)
    {
        printf("%d->", head->val);
        head = head->next;
    }
}
