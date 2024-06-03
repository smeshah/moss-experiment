
  /**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     struct ListNode *next;
   * };
   */
  struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
      struct ListNode* p=head;
      struct ListNode* t=NULL;
      int c=0,i=1;
      while(p!=NULL)
      {
          p=p->next;
          c++;
      }
      if(n==1&&c==1)//if only one element is in the list
          return NULL;
      p=head;
      if(c==n)//if first needs to be deleted i.e. c=2,n=2
      {
          head=head->next;
      }
      else{
      while(i!=c-n)//loop works till i reaches the index 
      {
          p=p->next;
          i++;
      }
      t=p->next;
      p->next=t->next;
      free(t);
      }
      return head;
  }
