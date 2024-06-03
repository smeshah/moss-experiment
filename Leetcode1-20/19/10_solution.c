
  /**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     struct ListNode *next;
   * };
   */
  struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

      int i = 1;
      int count = 0;
      struct ListNode* temp;
      temp = head;
      while (temp != 0) {
          temp = temp->next;
          count++;
      }

      n = count - n + 1;

      struct ListNode *temp1, *nextnode;
      if (n > 1) {
          temp1 = head;
          while (i < n - 1) {
              temp1 = temp1->next;
              i++;
          }
          nextnode = temp1->next;
          temp1->next = nextnode->next;
          free(nextnode);
          return head;
      }

      else if (n == 1) {
          temp1=head;
          //struct ListNode* p = temp1;
         // temp1 = temp1->next;
          return head->next;
      }

      return head;
  }

