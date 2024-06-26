
  /**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     struct ListNode *next;
   * };
   */
  struct ListNode* node(int val){
      struct ListNode* head = (struct ListNode* )malloc(sizeof(struct ListNode));
      head->val = val;
      head->next = NULL;
      return head;
  }

  struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
      struct ListNode* head = node(0);
      struct ListNode* ans = head;
      int sum = 0;
      while(l1!=NULL || l2!=NULL || sum){
          sum += (l1!=NULL?l1->val:0) + (l2!=NULL?l2->val:0);
          head->next = node(sum%10);
          sum /= 10;
          head = head->next;
          l1 = (l1!=NULL?l1->next:NULL);
          l2 = (l2!=NULL?l2->next:NULL);
      }
      return ans->next;
  }
