
  /**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     struct ListNode *next;
   * };
   */
  struct ListNode *create(int val){
      struct ListNode* tmp = malloc(sizeof(struct ListNode)); 
      tmp->next = NULL;
      tmp->val=val;
      return tmp;
  }

  struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
      struct ListNode* ans = malloc(sizeof(struct ListNode)); 
      struct ListNode* ret = ans;
      int add=0;
      int sum=0;

      while(l1 || l2){
          sum=(l1 ? l1->val : 0) + (l2 ? l2->val : 0) + add;
          if(sum>9){
              add=1;
              sum-=10;
          }
          else add=0;

          ans->next = create(sum);
          ans=ans->next;
          if(l1) l1=l1->next;
          if(l2) l2=l2->next;
      }

      if(add) ans->next=create(add);

      return ret->next;

  }
