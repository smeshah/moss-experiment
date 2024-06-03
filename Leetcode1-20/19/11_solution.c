
  /**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     struct ListNode *next;
   * };
   */
  struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
      struct ListNode *temp = head;
      int size = 0;
      while (temp != NULL) {
          temp = temp->next;
          size++;
      }
      if (size == n)
          head = head->next;
      else {
      temp = head;
      int counter = 0;
      while (counter != size - n) {
          temp = temp->next;
          counter++;
      }
      struct ListNode *temp1 = head;
      while (temp1->next != temp && temp1->next) temp1 = temp1->next;
      temp1->next = temp->next;
      }
      return head;
  }
