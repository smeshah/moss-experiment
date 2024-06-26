

  int GetLength(struct ListNode* head)
  {
  	struct ListNode* traverse = head;

  	int Length = 0;
  	while (traverse != NULL)
  	{
  		traverse = traverse->next;
  		Length++;
  	}

  	return Length;
  }
  struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

  	int length = GetLength(head);

  	// length is 1 and toBe delted is 1
  	if (length == 1 && n == 1) 
  		return NULL;

  	// 1st node deletion - simply returns head -> next
  	if (length == n)
  		return head -> next;

  	int deleteIndex = length - n - 1;


  	struct ListNode* traverse = head;
  	while (deleteIndex > 0)
  	{
  		traverse = traverse->next;
  		deleteIndex--;
  	}
  	traverse->next = traverse->next->next;
  	return head;
  }

