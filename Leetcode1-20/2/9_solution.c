
  /**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     struct ListNode *next;
   * };
   */


  struct ListNode *createNode(int val)
  {
      struct ListNode *n = malloc(sizeof(struct ListNode));
      n->next = NULL;
      n->val = val;
      return n;
  }

  struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
  {
      struct ListNode *n1 = l1;
      struct ListNode *n2 = l2;
      struct ListNode dummy_head = { .val=-1, .next=NULL };
      struct ListNode *h, *n;

      int res = 0;

      for (h = &dummy_head; n1 && n2; n1 = n1->next, n2 = n2->next) {
          int digit = n1->val + n2->val + res;
          n = createNode(digit % 10);
          res = digit / 10;
          h->next = n;
          h = n;
      }

      if (n2)
          n1 = n2;

      for (; n1; n1 = n1->next) {
          int digit = n1->val + res;
          n = createNode(digit % 10);
          res = digit / 10;
          h->next = n;
          h = n;
      }

      if (res > 0) {
          int digit = res;
          n = createNode(digit % 10);
          res = digit / 10;
          h->next = n;
          h = n;
      }

      return dummy_head.next;
  }
