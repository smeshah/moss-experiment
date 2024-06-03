
  /**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     struct ListNode *next;
   * };
   */
  struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
  {
    struct ListNode *head, *cur;
    int sum, ram;

    head = (struct ListNode*) malloc(sizeof(struct ListNode));
    cur = head;
    ram = 0;
    while(l1 != NULL || l2 != NULL || ram > 0) {
      sum = 0;
      if (l1 != NULL) {
          sum += l1->val;
          l1 = l1->next;
      }
      if (l2 != NULL) {
          sum += l2->val;
          l2 = l2->next;
      }
      cur->next = (struct ListNode*) malloc(sizeof(struct ListNode));
      cur = cur->next;
      cur->val = (sum + ram) % 10;
      ram = (sum + ram) / 10;
    }
    cur->next = NULL;
    return head->next;
  }

