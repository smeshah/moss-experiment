
  /**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     struct ListNode *next;
   * };
   */


  struct ListNode* throughList(struct ListNode* head, struct ListNode* previous)
  {
      if(head->next != NULL)
      {
          return throughList(head->next,previous->next);
      }
      else
      {
          if(previous->next->next == NULL)
          {
              previous->next =NULL ;
          }
          else
          {
              previous->next = previous->next->next;
          }
          return previous;
      }
  }


  struct ListNode* removeNthFromEnd(struct ListNode* head, int n){

      struct ListNode* ori = head;
      struct ListNode* current = head;

      for(int i = 0; i < n; i++)
      {
          current = current->next;
      }

      if(current == NULL) return head->next;

      throughList(current,ori);
      return head;
  }
