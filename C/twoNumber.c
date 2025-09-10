#include <stdio.h>
#include <stdlib.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

struct ListNode
{
    int val;
    struct ListNode *next;
    
};

int main(void) {

    struct ListNode *item1_l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *item2_l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *item3_l1 = (struct ListNode *)malloc(sizeof(struct ListNode));

    item1_l1->val = 2;
    item2_l1->val = 4;
    item3_l1->val = 3;

    item1_l1->next = item2_l1;
    item2_l1->next = item3_l1;
    item3_l1->next = NULL;

    struct ListNode *item1_l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *item2_l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *item3_l2 = (struct ListNode *)malloc(sizeof(struct ListNode));

    item1_l2->val = 5;
    item2_l2->val = 6;
    item3_l2->val = 4;

    item1_l2->next = item2_l2;
    item2_l2->next = item3_l2;
    item3_l2->next = NULL;
    
    struct ListNode *debug;
    
    debug = addTwoNumbers(item1_l1, item1_l2);

    while (debug != NULL)
    {
        printf("%d", debug->val);
        debug = debug->next;
    }
    

    free(item1_l1);
    free(item2_l1);
    free(item3_l1);

    free(item1_l2);
    free(item2_l2);
    free(item3_l2);

    return 0;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode *current = &dummy;
    int carry = 0;

    while(l1 != NULL || l2 != NULL || carry) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;

        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        current->next = newNode;
        current = current->next;
    }

    return dummy.next;
}
