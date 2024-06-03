
  /**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     struct ListNode *next;
   * };
   */
  struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
      if(head  == NULL) return NULL;
      struct ListNode* p = head;
      int cnt = 0;
      while(p != NULL){
          cnt++;
          p = p->next;
      }
      if(cnt < n) return NULL;
      n = cnt - n;
      if(n == 0){
          if(cnt == 1) return NULL;
          else{
              struct ListNode* q = head;
              head = q->next;
              free(q);
          }
      }else{
          p = head;
          while(n != 1){
              n--;
              p = p->next;
          }
          struct ListNode* q = p->next;
          p->next = q->next;
          free(q);
      }
      return head;
  }
