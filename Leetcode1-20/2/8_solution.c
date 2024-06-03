
    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     struct ListNode *next;
     * };
     */

    void insert(struct ListNode** head, int x) {
        struct ListNode* temp1 = (struct ListNode*)malloc(sizeof(struct ListNode));
        struct ListNode* temp2 = (*head);
        temp1->val = x;
        temp1->next = NULL;
        if(*head == NULL) {
            *head = temp1;
            //printf("%d
  ", (*head)->val);
            return;
        }
        while(temp2->next != NULL) {
            temp2 = temp2->next;
            //printf("1
  ");
        };
        temp2->next = temp1;
    };
    struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
        struct ListNode* l3 = NULL;
        int c = 0;
        // while(l1 != NULL) {
        //     printf("%d
  ", l1->val);
        //     l1 = l1->next;
        // };
        while(l1 != NULL || l2 != NULL) {
            int a = 0, b = 0;
            if(l1 != NULL) {
                a = l1->val;
            };
            if(l2 != NULL) {
                b = l2->val;
            };
            int x = a + b + c;
            if(x >= 10) {
                insert(&l3, x % 10);
                c = 1;
            }
            else {
                insert(&l3, x);
                c = 0;
            };
            printf("%d
  ", x);
            if(l1 != NULL) {
                l1 = l1->next;
            };
            if(l2 != NULL) {
                l2 = l2->next;
            };
        };
        if(c != 0) {
            insert(&l3, 1);
        };
        return l3;
    };
