

  struct ListNode* removeNthFromEnd(struct ListNode* head, int n)

  {  typedef struct ListNode ListNode;
      ListNode*p = head;
     ListNode*q = p->next;
     if(p->next==NULL) {head = NULL; return head;}
      int c=1;
      while(p->next !=NULL)
      {
          p = p->next;
          c++;
      }

      int index = c - n +1;
      p = head;

  	if(index==1)
      {
          head = q;
          free(p);
          return head;
      }

      for(int i=1; i<index-1;i++)
      {
          p = p->next;
          q = q->next;
      }

      p->next = q->next;
      free(q);

      return head;   

  }
