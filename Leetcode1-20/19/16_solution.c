  /**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     struct ListNode *next;
   * };
   */
  struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
      struct ListNode*fast,*slow,*dummy;
      struct ListNode*  temp = (struct ListNode *)malloc(sizeof(struct ListNode));
      if(head==NULL)
          return head;
      temp->next=head;
      int count=1;
      fast=temp;
      slow=temp;
      for(int i=1;i<=n;i++)
      {
          fast=fast->next;
      }
      while(fast->next!=NULL)
      {
          fast=fast->next;
          slow=slow->next;
      }
      dummy=slow->next;
      slow->next = slow->next->next;
      free(dummy);
      return temp->next;
  }