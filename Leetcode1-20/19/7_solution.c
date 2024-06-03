
  /**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     struct ListNode *next;
   * };
   */
  typedef struct ListNode node;
  struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
      int c = 1;
      node* tmp = head;
      while (tmp->next) {
          tmp = tmp->next;
          c++;
      }

      node NH;
      NH.next = head;
      node* pre = &NH;
      c -= n;
      for (int i = 0; i < c; i++) {
          pre = pre->next;
      }

      tmp = pre->next->next;
      pre->next = tmp;

      return NH.next;
  }
