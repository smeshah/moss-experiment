
  /**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     struct ListNode *next;
   * };
   */

  typedef struct res {
      struct ListNode *h;
      int n; // from the end, where the last is 1
  } res;

  struct res removeNth(struct ListNode *head, int n)
  {
      struct res res = {NULL, 0};
      if (head == NULL) {
          return res;
      }

      struct res next_res = removeNth(head->next, n);
      if (next_res.n == n) {
          if (head->next)
              head->next = head->next->next;
      }
      res.n = next_res.n + 1;
      res.h = head;
      return res;
  }

  struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
  {
      struct res res = removeNth(head, n);
      if (res.n == n)
          return head->next;
      return res.h;
  }
