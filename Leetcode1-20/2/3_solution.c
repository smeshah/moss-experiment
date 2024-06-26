
    struct ListNode *addNode(struct ListNode **headRef, int num)
    {
        struct ListNode *newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
        if (!newNode) {
            fprintf(stderr, "[ERROR] allocating memory fora new node.
  ");
            return newNode;
        }
        newNode->val = num;
        newNode->next = *headRef;
        *headRef = newNode;
        return newNode;
    }

    struct ListNode *reverse(struct ListNode *head)
    {
        if (head == NULL)
            return head;
        struct ListNode *prev = NULL;
        while (head) {
            struct ListNode *nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
    struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

        // we will assume that both lists have the same size
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        struct ListNode *newList = NULL;
        struct ListNode *curr = NULL;

        int sum = 0;
        while (l1 || l2) {
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            addNode(&newList, sum);
            //printf("sum: %d
  ", sum);
            sum = 0;
        }

        newList = reverse(newList);
        curr = newList;
        while (curr) {
            if (curr->val >= 10) {
                curr->val = curr->val - 10;
                if (!curr->next ){
                    curr->next = malloc(sizeof(struct ListNode));
                    curr->next->next = NULL;
                    curr->next->val = 0;
                }
                curr->next->val += 1;
            }
            curr = curr->next;
        }
        return newList;
    }

    /*
    Runtime: 12 ms, faster than 84.73% of C online submissions for Add Two Numbers.
    Memory Usage: 8.8 MB, less than 72.00% of C online submissions for Add Two Numbers.
    */
