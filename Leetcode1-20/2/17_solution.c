
  struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
      struct ListNode dummyHead = {0}, *prev = &dummyHead, *node;
      int sum = 0;
      while (l1 || l2 || sum) {
          if (l1) {
              sum += l1->val;
              l1 = l1->next;
          }
          if (l2) {
              sum += l2->val;
              l2 = l2->next;
          }
          node = malloc(sizeof(struct ListNode));
          node->val = sum % 10;
          node->next = NULL; 
          sum /= 10;
          prev->next = node;
          prev = prev->next;
      }
      return dummyHead.next;
  }
