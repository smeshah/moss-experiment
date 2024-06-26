
  /**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     struct ListNode *next;
   * };
   */

  struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
      int val=0;
      int reminder=0;
      struct ListNode* root;
      struct ListNode* l3 = NULL;
      struct ListNode *new;

      while(l1 && l2) {
          val = (l1->val+l2->val+reminder)%10;

          new = malloc(sizeof (struct ListNode));
          new->val = val; new->next = NULL;
          if(l3) l3->next = new;
          else root=new;
          l3 = new;

          reminder = (l1->val+l2->val+reminder)/10;
          l1 = l1->next;      
          l2 = l2->next;

      }
      while (l1) {
          val = (l1->val+reminder)%10;

          new = malloc(sizeof (struct ListNode));
          new->val = val; new->next = NULL;
          if(l3) l3->next = new;
          else root=new;
          l3 = new;

          reminder = (l1->val+reminder)/10;
          l1 = l1->next;
      }
      while(l2) {
          val = (l2->val+reminder)%10;

          new = malloc(sizeof (struct ListNode));
          new->val = val; new->next = NULL;
          if(l3) l3->next = new;
          else root=new;
          l3 = new;

          reminder = (l2->val+reminder)/10;
          l2 = l2->next;
      }

      if(reminder) {
          val = reminder;

          new = malloc(sizeof (struct ListNode));
          new->val = val; new->next = NULL;
          if(l3) l3->next = new;
          else root=new;
          l3 = new;

      }
      return root;
  }
