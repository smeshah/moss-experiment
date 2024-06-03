
  /**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     struct ListNode *next;
   * };
   */
  struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
      struct ListNode *temp = head, *pre = NULL;
      // Count the no of nodes.
      int c = 0;
      while(temp) {
          c++;
          temp = temp->next;
      }

      if (c==1 && n==1) return NULL;


      if (c-n==0) {
          head = head->next;
          return head;
      }

      temp = head;
      for (int i=0; i<c-n; i++) {
          pre = temp;
          temp = temp->next;
      }
      if (pre && pre->next != NULL)
          pre->next = temp->next;

      return head;
  }
