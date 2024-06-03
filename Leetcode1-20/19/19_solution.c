
  /**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     struct ListNode *next;
   * };
   */
  struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
      if(head==NULL || (head->next==NULL)){
          return NULL;
      }
      int i=0,a;
      struct ListNode *temp,*d;
      temp=head;
      while(temp!=NULL){
          i++;
          temp=temp->next;
      }
      if(n==i)
      return head->next;
      temp=head;
      a=i-n-1;
      while(a!=0){
          temp=temp->next;
          a--;
      }
      d=temp->next;
      temp->next=temp->next->next;
      free(d);
      return head;
  }
