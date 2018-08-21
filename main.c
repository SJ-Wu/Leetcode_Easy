#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* creatList(int*, int);
struct ListNode* mergeTwoLists(struct ListNode*, struct ListNode*);
void printList(struct ListNode*);

int main(void)
{

    //int arr1[]={1,2,4}, arr2[]={1,3,4};
    int arr1[]={1,3,7}, arr2[]={4,5,6};
    struct ListNode *ls1, *ls2, *sum;
    ls1 = creatList(arr1, 3);
    ls2 = creatList(arr2, 3);
    sum = mergeTwoLists(ls1, ls2);
    printf("Merger list:");
    printList(sum);
    //printList(ls1);
    //printList(ls2);
    getchar();
    return 0;
}

struct ListNode* creatList(int* arr, int len){
    int i;
    struct ListNode *first, *current, *previous;
    for(i=0;i<len;i++){
        current = (struct ListNode*) malloc(sizeof(struct ListNode));
        current->val = arr[i];
        if(i == 0)
        {
            first = current;
        }
        else
        {
            previous->next = current;
        }
        current->next = NULL;
        previous = current;
    }
    return first;
}


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode* temp1 = l1;
    struct ListNode* temp2 = l2;
    struct ListNode* node;

    if(l1 == NULL){
        return l2;
    }
    if(l2 == NULL){
        return l1;
    }

    while(temp2 != NULL){
        printf("List1 ");
        printList(l1);
        printf("List2 ");
        printList(temp2);
        while(temp1 != NULL){
            if(temp1->val == temp2->val){
                node = temp2;
                temp2 = temp2->next;
                node->next = temp1->next;
                temp1->next = node;
                break;
            }
            else if (temp2->val > temp1->val)
            {
                if (temp1->next == NULL)
                {
                    node = temp2;
                    temp2 = temp2->next;
                    node->next = temp1->next;
                    temp1->next = node;
                    break;
                }
                else if (temp2->val > temp1->next->val)
                {
                    temp1 = temp1->next;
                }
            }
            else if(temp2->val < temp1->val){
                node = temp2;
                temp2 = temp2->next;
                node->next = temp1;
                break;
            }
            else
            {
                node = temp2;
                temp2 = temp2->next;
                node->next = temp1->next;
                temp1->next = node;
                break;
            }
        }
    }
    return l1;
}

void printList(struct ListNode* first){
    struct ListNode *node = first;
    if(first == NULL)
    printf("The list is empty");
    else{
        while(node != NULL){
            printf("%3d", node->val);
            node = node->next;
        }
        printf("\n");
    }
}
