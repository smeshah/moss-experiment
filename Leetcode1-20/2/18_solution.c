
  /**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     struct ListNode *next;
   * };
   */
  struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
      struct ListNode  node;
      struct ListNode* p = &node;
      int count = 0;
      while (l1 != NULL || l2 != NULL || count != 0) {
          if (l1 != NULL) {
              count += l1->val;
              l1 = l1->next;
          }
          if (l2 != NULL) {
              count += l2->val;
              l2 = l2->next;
          }
          p = p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
          p->val = count % 10;
          count /= 10;
      }
      p->next = NULL;
      return node.next;
  }
